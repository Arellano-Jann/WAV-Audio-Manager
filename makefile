wavman: main.cpp Processor.o Wav.o
	g++ -o wavman main.cpp Processor.o Wav.o

Processor.o: Processor.cpp Processor.h
	g++ -c Processor.cpp

Wav.o: Wav.cpp Wav.h
	g++ -c Wav.cpp

clean:
	rm *.o wavman