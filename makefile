main.exe: HeapSort.o
	gcc HeapSort.o -o main.exe

HeapSort.o: HeapSort.cpp
	gcc -g -c HeapSort.cpp

clean: 
	rm -f *.o
	rm -f *.exe
