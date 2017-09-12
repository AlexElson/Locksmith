all: main.cpp library.o media.o book.o film.o periodical.o video.o
	g++ -o Project1 main.cpp media.o library.o book.o periodical.o film.o video.o

media.o: media.cpp media.h
	g++ -c media.cpp media.h

library.o: library.cpp library.h
	g++ -c library.cpp library.h

book.o: book.cpp book.h
	g++ -c book.cpp book.h

periodical.o: periodical.cpp periodical.h
	g++ -c periodical.cpp periodical.h

film.o: film.cpp film.h
	g++ -c film.cpp film.h

video.o: video.cpp video.h
	g++ -c video.cpp video.h

clean:
	rm -f *.o *.h.gch
