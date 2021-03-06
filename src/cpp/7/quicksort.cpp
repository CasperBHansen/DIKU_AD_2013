/*
 * 	quicksort.cpp
 *
 * 	An implementation of quick sort in C++.
 *
 */


#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include "../utilities.h"


#pragma mark PARTITIONING FUNCTIONS

template <class T>
int partition(T * A, int p, int r) {
	
	T x = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
		if (A[j] <= x)
			manipulate::swap<T>(A, ++i, j);
	i++;
	manipulate::swap<T>(A, i, r);
	return i;
}


#pragma mark ALGORITHM

template <class T>
void quicksort(T * A, int p, int r) {
	
	if (p >= r)
		return;
		
	int q = partition(A, p, r);
	quicksort(A, p, q - 1);
	quicksort(A, q + 1, r);
}


#pragma mark MAIN PROGRAM

int main(int argc, char * argv[]) {
	
	int n = 8;
	int A[n];
	
	srand(time(0));
	for (int i = 0; i < n; ++i)
		A[i] = rand() % n;
	
	cout << "Unsorted: ";
	debug::print_array(A, n);
	
	quicksort(A, 0, n-1);
	
	cout << "Sorted: ";
	debug::print_array(A, n);
	
	return 0;
}
