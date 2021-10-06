sortmain: sortmain.o ArrayFile.o selectionsort.o insertionsort.o bubblesort.o
	g++ sortmain.o ArrayFile.o selectionsort.o insertionsort.o bubblesort.o -o output

sortmain.o: sortmain.cpp
	g++ -c sortmain.cpp

selectionsort.o: selectionsort.cpp selectionsort.h
	g++ -c selectionsort.cpp

bubblesort.o: bubblesort.cpp bubblesort.h
	g++ -c bubblesort.cpp

insertionsort.o: insertionsort.cpp insertionsort.h
	g++ -c insertionsort.cpp
	
mergesort.o: mergesort.cpp mergesort.h
	g++ -c mergesort.cpp

quicksort.o: quicksort.cpp quicksort.h
	g++ -c quicksort.cpp

ArrayFile.o: ArrayFile.cpp ArrayFile.h
	g++ -c ArrayFile.cpp

clean: 
	rm *.o output
