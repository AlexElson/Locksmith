all: main.cpp library.o media.o book.o film.o periodical.o video.o
	g++ -o Project1 main.cpp media.o library.o book.o periodical.o film.o video.o

media.o: media.cpp media.h
	g++ -c media.cpp

library.o: library.cpp library.h
	g++ -c library.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

periodical.o: periodical.cpp periodical.h
	g++ -c periodical.cpp

film.o: film.cpp film.h
	g++ -c film.cpp

video.o: video.cpp video.h
	g++ -c video.cpp

clean:
	rm -f *.o *.h.gch
