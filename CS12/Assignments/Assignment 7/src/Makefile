COMPILE = g++
OBJS = message.o reply.o topic.o bboard.o user.o
BOARD_DEPS = message.o reply.o topic.o
FLAGS = -W -Wall -Werror -pedantic -ansi

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o BBoard.exe main.cpp $(OBJS)

message.o: message.cpp message.h
	$(COMPILE) $(FLAGS) -c message.cpp

reply.o: reply.cpp reply.h
	$(COMPILE) $(FLAGS) -c reply.cpp

topic.o: topic.cpp topic.h
	$(COMPILE) $(FLAGS) -c topic.cpp

bboard.o: bboard.cpp bboard.h
	$(COMPILE) $(FLAGS) -c bboard.cpp

user.o: user.cpp user.h
	$(COMPILE) $(FLAGS) -c user.cpp

clean:
	del /S *.o *~
