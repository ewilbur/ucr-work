COMPILE = g++
OBJS = Martian.o Dumb.o Smart.o Cache.o
FLAGS = -W -Wall -Werror -pedantic -ansi

all: main.cpp $(OBJS)
	$(COMPILE) -o hw2.exe main.cpp $(OBJS)

Martian.o: Martian.cpp Martian.h
	$(COMPILE) -c Martian.cpp

Dumb.o: Dumb.cpp Dumb.h
	$(COMPILE) -c Dumb.cpp

Smart.o: Smart.cpp Smart.h
	$(COMPILE) -c Smart.cpp

Cache.o: Cache.cpp Cache.h
	$(COMPILE) -c Cache.cpp

clean:
	rm *.o
