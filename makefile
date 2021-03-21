all: SpotifyLite

SpotifyLite: Song.o
	g++ -g Song.o -o SpotifyLite

Song.o: Song.cpp Song.h
	g++ -c -g main.cpp -o Song.o

clear: 
	rm *.o SpotifyLite
