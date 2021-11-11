wavman: main.cpp Processor.o Wav.o
	g++ -std=c++11 -o wavman main.cpp Processor.o Wav.o

Processor.o: Processor.cpp Processor.h
	g++ -std=c++11 -c Processor.cpp

Wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ -std=c++11 -c Wav.cpp

clean:
	rm *.o wavman