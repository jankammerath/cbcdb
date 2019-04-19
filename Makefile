CC = g++
CFLAGS = `pkg-config --cflags --libs glib-2.0 libconfig++ libmicrohttpd`

# this makes the binary
all:
	$(CC) -o bin/cbcdb src/*.cpp src/class/*.cpp $(CFLAGS)
