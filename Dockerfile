FROM fedora:28

RUN dnf install -y make gcc-c++

RUN g++ -v