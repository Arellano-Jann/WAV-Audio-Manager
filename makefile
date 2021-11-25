HDIR = headers # directories/folders
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11 -w # flags. might not need -w since it doesn't seem to do anything
DEPS = $(wildcard $(HDIR)/*.h)
SOURCE = $(wildcard $(CDIR)/*.cpp) # essentially equals everything in CDIR that has ending of .cpp
OBJS = $(patsubst %.cpp, $(ODIR)/%.o, $(SOURCE)) # replaces everything in source ending in arg1 with arg2
vpath %.h headers # basically a search function
vpath %.cpp src
vpath %.o objs

$(ODIR)/%.o: $(CDIR)/%.cpp $(DEPS)
	g++ $(CPPFLAGS) -c -o $@ $<

wavman: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $^

clean:
	rm $(ODIR)/*.o wavman