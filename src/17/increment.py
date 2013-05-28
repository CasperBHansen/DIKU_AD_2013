#! /usr/bin/python2

def increment(A):
	i = 0
	# ...
	while i < len(A) and A[i] == 1:
		A[i] = 0
		i = i + 1
	# ...
	if i < len(A):
		A[i] = 1


def main():
	A = [0,0,0,0,0,0,0,0]
	n = 16
	
	for i in range(n):
		increment(A)
	
	print ''.join([str(bit) for bit in A][::-1])


if __name__ == '__main__':main()
