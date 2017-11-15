#!/usr/bin/env python

from distutils.core import setup

setup(name='pycmdstan',
      version='0.0',
      description='Python interface to CmdStan',
      author='Marmaduke Woodman',
      author_email='marmaduke.woodman@univ-amu.fr',
      url='https://github.com/maedoc/pycmdstan/',
      packages=['pycmdstan'],
      scripts=['bin/pycmdstan']
     )