mallickMohammadAdibA1: mallickMohammadAdibA1.o mallickMohammadAdibA1Main.o
	gcc -Wall -std=c99 mallickMohammadAdibA1.o mallickMohammadAdibA1Main.c -o mallickMohammadAdibA1
mallickMohammadAdibA1.o: mallickMohammadAdibA1.c givenA1.h
	gcc -Wall -std=c99 -c mallickMohammadAdibA1.c
mallickMohammadAdibA1Main.o: mallickMohammadAdibA1Main.c givenA1.h
	gcc -Wall -std=c99 -c mallickMohammadAdibA1Main.c
clean:
	rm *.o mallickMohammadAdibA1 

	