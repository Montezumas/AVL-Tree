driverAVL: MyDriver.o AVL.o
	g++ -o driverAVL MyDriver.o AVL.o

MyDriver.o: MyDriver.cpp AVL.h
	g++ -c MyDriver.cpp

AVL.o: AVL.cpp
	g++ -c AVL.cpp

clean:
	rm driverAVL *.o