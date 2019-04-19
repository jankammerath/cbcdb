CC = g++
CFLAGS = `pkg-config --cflags --libs libconfig++ libmicrohttpd jsoncpp openssl`

# this makes the binary
all:
	$(CC) -o bin/cbcdb src/*.cpp src/*/*.cpp src/*/*/*.cpp $(CFLAGS)
