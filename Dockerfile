# use the gcc docker images
FROM opensuse/tumbleweed:latest

# add the local directory as workdir in root
WORKDIR /cbcdb/

# install required libs
RUN zypper -n install gcc-c++ make libconfig++-devel libmicrohttpd-devel jsoncpp-devel libopenssl-devel

# install development tools
RUN zypper -n install valgrind gdb