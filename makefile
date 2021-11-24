HDIR = headers
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11
DEPS = Processor.h Wav.h WaveHeader.h
OBJS = main.cpp Processor.o Wav.o
vpath %.h headers
vpath %.cpp src
vpath %.o objs

#$(ODIR)/Processor.o: Processor.cpp Processor.h
#	g++ $(CPPFLAGS) -c $< -o $@

#Wav.o: Wav.cpp Wav.h WaveHeader.h
#	g++ $(CPPFLAGS) -c $< -o $@

$(ODIR)/%.o: %.cpp $(DEPS)
	g++ $(CPPFLAGS) -c $< -o $@

wavman: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $^

clean:
	rm *.o wavman