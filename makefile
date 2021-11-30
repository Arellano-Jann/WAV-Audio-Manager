HDIR = headers # directories/folders
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11 -w # flags. might not need -w since it doesn't seem to do anything
DEPS = $(wildcard $(HDIR)/*.h)
SOURCE = $(wildcard $(CDIR)/*.cpp) # essentially equals everything in CDIR that has ending of .cpp
OBJS = $(patsubst $(CDIR)/%.cpp, $(ODIR)/%.o, $(SOURCE)) # replaces everything in source ending in arg1 with arg2
vpath %.h headers # basically a search function
vpath %.cpp src
vpath %.o objs
DIRS = HDIR CDIR ODIR
$(shell mkdir -p $(DIRS))

#replace top of file with this if something is not working
# need to bug test objs and source
# HDIR = headers
# CDIR = src
# ODIR = objs
# CPPFLAGS = -std=c++11 -w
# DEPS = Processor.h Wav.h WaveHeader.h Compressor.h Echo.h Gain.h LowPassFilter.h Normalization.h UI.h
# OBJS = $(ODIR)/main.o $(ODIR)/Processor.o $(ODIR)/Wav.o $(ODIR)/Compressor.o $(ODIR)/Echo.o $(ODIR)/Gain.o $(ODIR)/LowPassFilter.o $(ODIR)/Normalization.o $(ODIR)/UI.o
# vpath %.h headers
# vpath %.cpp src
# vpath %.o objs

$(ODIR)/%.o: %.cpp $(DEPS)
	g++ $(CPPFLAGS) -c $< -o $@

wavman: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $^

clean:
	rm $(ODIR)/*.o wavman