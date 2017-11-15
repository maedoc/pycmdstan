#!/usr/bin/env python3

import os
import sys
import time
import subprocess
import numpy as np


def _rdump_array(key, val):
    c = 'c(' + ', '.join(map(str, val.flat)) + ')'
    if (val.size,) == val.shape:
        return '{key} <- {c}'.format(key=key, c=c)
    else:
        dim = '.Dim = c{0}'.format(val.shape)
        struct = '{key} <- structure({c}, {dim})'.format(
            key=key, c=c, dim=dim)
        return struct


def rdump(fname, data):
    """Dump a dict of data to a R dump format file.
    """
    with open(fname, 'w') as fd:
        for key, val in data.items():
            if isinstance(val, np.ndarray) and val.size > 1:
                line = _rdump_array(key, val)
            else:
                try:
                    val = val.flat[0]
                except:
                    pass
                line = '%s <- %s' % (key, val)
            fd.write(line)
            fd.write('\n')


def merge_csv_data(*csvs):
    data_ = {}
    for csv in csvs:
        for key, val in csv.items():
            if key in data_:
                data_[key] = np.concatenate(
                    (data_[key], val),
                    axis=0
                )
            else:
                data_[key] = val
    return data_


def parse_csv(fname):
    if '*' in fname:
        import glob
        return parse_csv(glob.glob(fname))
    if isinstance(fname, (list, tuple)):
        return merge_csv_data(*[parse_csv(_) for _ in fname])
    
    lines = []
    with open(fname, 'r') as fd:
        for line in fd.readlines():
            if not line.startswith('#'):
                lines.append(line.strip().split(','))
    names = [field.split('.') for field in lines[0]]
    data = np.array([[float(f) for f in line] for line in lines[1:]])

    namemap = {}
    maxdims = {}
    for i, name in enumerate(names):
        if name[0] not in namemap:
            namemap[name[0]] = []
        namemap[name[0]].append(i)
        if len(name) > 1:
            maxdims[name[0]] = name[1:]

    for name in maxdims.keys():
        dims = []
        for dim in maxdims[name]:
            dims.append(int(dim))
        maxdims[name] = tuple(reversed(dims))

    # data in linear order per Stan, e.g. mat is col maj
    # TODO array is row maj, how to distinguish matrix v array[,]?
    data_ = {}
    for name, idx in namemap.items():
        new_shape = (-1, ) + maxdims.get(name, ())
        data_[name] = data[:, idx].reshape(new_shape)

    return data_

def csv2mode(csv_fname, mode=None):
    csv = parse_csv(csv_fname)
    data = {}
    for key, val in csv.items():
        if key.endswith('__'):
            continue
        if mode is None:
            val_ = val[0]
        elif mode == 'mean':
            val_ = val.mean(axis=0)
        elif mode[0] == 'p':
            val_ = np.percentile(val, int(mode[1:]), axis=0)
        data[key] = val_
    return data

def csv2r(csv_fname, r_fname=None, mode=None):
    data = csv2mode(csv_fname, mode=mode)
    r_fname = r_fname or csv_fname.replace('.csv', '.R')
    rdump(r_fname, data)


from threading import Thread
class FollowCSV:
    def __init__(self, csv_fname):
        self.csv_fname = csv_fname
        self.thread = Thread(target=self._run)
        self.thread.start()
        self._line = ''
        self.read = True
    @property
    def line(self):
        self.read = True
        return self._line
    def _run(self):
        while True:
            try:
                self._follow()
            except Exception as exc:
                print(exc)
    def _follow(self):
        with open(self.csv_fname, 'r') as fd:
            while True:
                line = fd.readline()
                if line:
                    self._line = line
                    self.read = False
                else:
                    time.sleep(0.2)