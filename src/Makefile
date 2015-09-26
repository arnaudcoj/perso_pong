GPP=g++

IDIR =../include
ODIR=../obj

CFLAGS=-I$(IDIR) -Wall -g -std=c++11 

LIBS=-lsfml-window -lsfml-graphics -lsfml-system

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Entity.o Paddle.o Ball.o Strategy.o Human.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: clean Pong execute

Pong:../Pong

../Pong: $(OBJ) Pong.cpp
	$(GPP) -o $@ $^ $(CFLAGS) $(LIBS) 

$(ODIR)/%.o: %.cpp $(DEPS)
	$(GPP) -c -o $@ $< $(CFLAGS)

execute:../Pong
	cd .. && ./Pong && cd src

clean:
	rm -f $(ODIR)/*.o *~ ../Pong $(IDIR)/*~
