/*
 * utilities.h
 *
 * A collection of useful functions for debugging and testing algorithms.
 *
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
using std::cout;
using std::endl;


namespace manipulate {
	
	// swaps elements with indices i and j of an array A. 
	template <class T>
	void swap(T * A, int i, int j) {
		T tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
}

namespace debug {
	
	// prints the contents of an array A with n elements
	template <class T>
	void print_array(T * A, int n) {
		
		cout << "[";
		for (int i = 0; i < n; ++i) {
			cout << A[i];
			if (i != n-1)
				cout << ", ";
			else
				cout << "]" << endl;
		}
	}
}

#endif

