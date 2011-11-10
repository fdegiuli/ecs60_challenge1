a.out: database.o filmDriver.o string.o
	g++ -Wall -ansi -g -o film.out database.o filmDriver.o 

database.o: database.cpp database.h filmDriver.h 
	g++ -Wall -ansi -g -c database.cpp

filmDriver.o: filmDriver.cpp filmDriver.h database.h CPUTimer.h 
	g++ -Wall -ansi -g -c filmDriver.cpp

string.o: string.cpp mystring.h
	g++ -Wall -ansi string.cpp

clean:
	rm -f film.out database.o filmDriver.o 
