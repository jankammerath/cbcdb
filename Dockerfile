# use the gcc docker images
FROM opensuse/tumbleweed:latest

# add the local directory as workdir in root
WORKDIR /cbcdb/

# run a system update and install required libs
RUN zypper -n install gcc-c++ make libconfig++-devel libmicrohttpd-devel jsoncpp-devel libopenssl-devel