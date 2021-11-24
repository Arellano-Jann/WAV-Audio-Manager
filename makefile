HDIR = headers
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11
DEPS = Processor.h Wav.h WaveHeader.h
OBJS = Processor.o Wav.o
vpath %.h headers
vpath %.cpp src
vpath %.o objs

# change this stuff to implicit rules
wavman: main.cpp Processor.o Wav.o
	g++ $(CPPFLAGS) -o $@ $^

Processor.o: Processor.cpp Processor.h
	g++ $(CPPFLAGS) -c $< -o $@

Wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ $(CPPFLAGS) -c $< -o $@

#%.o: %.c $(DEPS)
#  $(CC) -c -o $@ $< $(CPPFLAGS)

clean:
	rm *.o wavman