CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : Synth.o Oscillator.o RingMod.o Melody.o Noise.o Saw.o Square.o jack_module.o main.o
				$(CC) -o $@ $(CFLAGS) Synth.o Oscillator.o RingMod.o Melody.o Noise.o Saw.o Square.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f example
