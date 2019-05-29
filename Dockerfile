FROM debian:stretch
RUN apt-get update
RUN apt-get install -y python gcc g++ make
WORKDIR home/
ADD libuv ./libuv/
ADD gyp ./gyp/
ADD build.gyp main.cc compile.sh ./
RUN ./compile.sh
CMD ./build/out/Default/libuv-stripped
