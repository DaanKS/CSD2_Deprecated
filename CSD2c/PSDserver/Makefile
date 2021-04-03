CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++17 -pthread
LDFLAGS= -ljack -lpthread

all: example

example : jack_module.o Saw.o circBuffer.o HardClip.o Server.o main.o
	$(CC) -o $@ $(CFLAGS) jack_module.o Saw.o circBuffer.o HardClip.o Server.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
