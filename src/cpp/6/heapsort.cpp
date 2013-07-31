/*
 * heapsort.cpp
 *
 * An implementation of heap sort in C++.
 *
 */

#define DEBUG

#include <malloc.h>
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

#include "../utilities.h"

typedef enum {
	MAX_HEAP,
	MIN_HEAP
} HEAP_PROPERTY;

template <class T>
class Heap {

public:
	Heap(T * A, int n)
	{
		array = A;
		length = n;
		size = 0;
	}
	
	~Heap()
	{
	}
	
	void print()
	{
		cout << "Array: " << endl;
		debug::print_array(array, length);
		cout << endl << "Heap: " << endl;
		T * tmp = array;
		for (int i = 1; i < size; i*=2) {
			debug::print_array(array, i);
			array += i;
		}
		array = tmp;
		cout << endl;
	}
	
	void build_max_heap() {
		size = length;
		for (int i = floorf(length / 2.0); i >= 0 ; --i)
			max_heapify(i);
	}
	
	void sort() {
		build_max_heap();
		for (int i = length - 1; i >= 0; --i) {
			manipulate::swap<T>(array, 0, i);
			--size;
			max_heapify(0);
		}
	}

private:
	int parent(int i) {
		return floor(i / 2.0);
	}
	
	int left(int i) {
		return 2 * (i + 1) - 1;
	}
	
	int right(int i) {
		return (2 * (i + 1) - 1) + 1;
	}
	
	void max_heapify(int i) {
		int l = left(i);
		int r = right(i);
		int largest;
		
		if (l < size && array[l] > array[i])
			largest = l;
		else
			largest = i;
		
		if (r < size && array[r] > array[largest])
			largest = r;
		
		if (largest != i) {
			manipulate::swap<T>(array, i, largest);
			max_heapify(largest);
		}
	}
	
private:
	T * array;
	int length, size;
};


#pragma MAIN PROGRAM

int main(int argc, char * argv[]) {
	
	int n = 10;
	int A[16] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 0, 0, 0, 0, 0};
		
	Heap<int> * heap = new Heap<int>(A, n);
	
	heap->build_max_heap();
	heap->print();
	heap->sort();
	
	// the array is now sorted, and we can discard the heap object
	delete heap;
	
	// test that the array is in fact sorted
	cout << "A: ";
	debug::print_array(A, n);
	
	return 0;
}

