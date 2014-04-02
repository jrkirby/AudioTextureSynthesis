OFILES= AudioWindow.o Audio.o FreqVector.o Neighbors.o 
LIB= -lsndfile -lfftw3

all: main

main: main.cpp $(OFILES)
	g++ -o main main.cpp $(OFILES) $(LIB)

Audio.o: Audio.cpp
	g++ -c Audio.cpp -o Audio.o $(LIB)

AudioWindow.o: AudioWindow.cpp
	g++ -c Audio.cpp -o Audio.o $(LIB)

FreqVector.o: FreqVector.cpp
	g++ -c FreqVector.cpp -o FreqVector.o $(LIB)

Neighbors.o: Neighbors.cpp
	g++ -c Neighbors.cpp -o Neighbors.o $(LIB)


