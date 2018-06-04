FROM python:3.6-stretch

ENV CSVER=2.17.1
ENV CMDSTAN=cmdstan-2.17.1

RUN pip install numpy python-coveralls coverage
RUN curl -OL https://github.com/stan-dev/cmdstan/releases/download/v$CSVER/cmdstan-$CSVER.tar.gz \
 && tar xzf cmdstan-$CSVER.tar.gz \
 && rm -rf cmdstan-$CSVER.tar.gz \
 && cd cmdstan-$CSVER \
 && make CC=g++ build

RUN pip install matplotlib
ENV CMDSTAN=/cmdstan-2.17.1

RUN make -C $CMDSTAN examples/bernoulli/bernoulli

RUN mkdir -p /opt/pycmdstan
WORKDIR /opt/pycmdstan
ADD ./ /opt/pycmdstan/

# fix me