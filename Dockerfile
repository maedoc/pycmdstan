FROM python:3.6-stretch

ENV CSVER=2.17.1
ENV CMDSTAN=cmdstan-2.17.1

RUN apt-get update && apt-get install -y clang-3.9
RUN pip install numpy coverage pytest pytest-cov pytest-xdist matplotlib filelock

WORKDIR /opt/
RUN curl -OL https://github.com/stan-dev/cmdstan/releases/download/v$CSVER/cmdstan-$CSVER.tar.gz \
 && tar xzf cmdstan-$CSVER.tar.gz \
 && rm -rf cmdstan-$CSVER.tar.gz \
 && cd cmdstan-$CSVER \
 && make CXX=clang++-3.9 -j8 build examples/bernoulli/bernoulli

ENV CMDSTAN=/opt/cmdstan-2.17.1

RUN make -C $CMDSTAN 

RUN mkdir -p /opt/pycmdstan
WORKDIR /opt/pycmdstan
ADD ./ /opt/pycmdstan/

RUN pip install --upgrade setuptools wheel twine

# fix me