#Programmed by: Alexander Osborn
#email: axo095120@utdallas.edu
#CS3377.002

#Compiler flags
CXX= g++
CXXFLAGS=
CPPFLAGS= -Wall -I/scratch/perkins/include
LDFLAGS= -L/scratch/perkins/lib
LDLIBS= -lcdk -lcurses

#The exec file
EXEC=program6

#Object files
OBJS= program6.o


#targets
all: $(EXEC)

#Crate will make a tarball
crate: $(EXEC)
	mkdir -p ./prog6
	cp *.cc *.h Makefile README_axo095120 prog6
	tar czfv prog6.tar.gz prog6
	rm -rf ./prog6

clean:
	rm -f *.o $(EXEC) *~ \#*

$(EXEC):$(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

