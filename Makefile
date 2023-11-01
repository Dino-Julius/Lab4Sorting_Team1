#  *----------------------------------------------------------
#  * Lab #4: Sorting Algorithms
#  *
#  * Date: October-2023
#  * Authors:
#  *           A01749879 Julio Cesar Vivas Medina
#  *           A01798380 Ulises Jaramillo Portilla
#  *----------------------------------------------------------

CXX = g++
CXXFLAGS = -g

SORT_ALGORITHMS = insertionSort selectionSort bubbleSort quickSort mergeSort countingSort stdSort
EXECS = $(SORT_ALGORITHMS)

all: $(EXECS)

%: %.o
	$(CXX) $< -o $@

%.o: %.cpp Lab4_Sorting.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECS) *.o
