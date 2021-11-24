HDIR = headers
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11
DEPS = Processor.h Wav.h WaveHeader.h
OBJS = main.cpp Processor.o Wav.o
vpath %.h headers
vpath %.cpp src
vpath %.o objs


$(ODIR)/%.o: %.cpp $(DEPS)
	g++ $(CPPFLAGS) -o $@ -c $<

wavman: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $^

clean:
	rm *.o wavman


#DEPS = $(wildcard src/*.h)
#SOURCE = $(wildcard src/*.cpp)
#OBJS = $(patsubst %.cpp, %.o, $(SOURCE)) # replace these with line 5 a