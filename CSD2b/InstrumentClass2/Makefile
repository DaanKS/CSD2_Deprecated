playtest: main.o Instrument.o
	g++ -o playtest main.o Instrument.o

main.o: main.cpp Instrument.h
	g++ -c main.cpp

Instrument.o: Instrument.cpp Instrument.h
	g++ -c Instrument.cpp

clean:
	rm playtest main.o Instrument.o
