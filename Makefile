CC = g++
CFLAGS = `pkg-config --cflags --libs glib-2.0 libconfig++ libmicrohttpd jsoncpp`

# this makes the binary
all:
	$(CC) -o bin/cbcdb src/*.cpp src/class/*.cpp src/class/Request/*.cpp $(CFLAGS)
