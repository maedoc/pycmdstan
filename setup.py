#!/usr/bin/env python

import setuptools


def readme_contents() -> str:
    with open('README.md', 'r') as fd:
        src = fd.read()
    return src


setuptools.setup(
    name='pycmdstan',
    version='0.1',
    description='Python interface to CmdStan',
    long_description=readme_contents(),
    long_description_content_type="text/markdown",
    author='Marmaduke Woodman',
    author_email='marmaduke.woodman@univ-amu.fr',
    url='https://gitlab.thevirtualbrain.org/tvb/pycmdstan',
    packages=['pycmdstan'],
    classifiers=(
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: Apache Software License",
        "Operating System :: OS Independent",
    ),
)