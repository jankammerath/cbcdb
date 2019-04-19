CC = g++
CFLAGS = `pkg-config --cflags --libs libconfig++ libmicrohttpd jsoncpp openssl`

# this makes the binary
all:
	$(CC) -o bin/cbcdb src/*.cpp src/class/*.cpp src/class/Request/*.cpp $(CFLAGS)
