wavman: main.cpp Processor.o Wav.o
	g++ -std=c++11 -o wavman main.cpp Processor.o Wav.o

Processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp

Wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ -c -std=c++11 Wav.cpp

clean:
	rm *.o wavman