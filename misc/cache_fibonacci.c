#include <math.h>
#include <stdio.h>
#include <stdlib.h>


unsigned long long fib(int term) {
	// sizeof(long long) == 8 bytes
	// 4 x 8 bytes = 32 bytes (reasonable guess <= cache line size)
	// so the fib array should stay in the cache...
	// use a small circular buffer of size 4 to reduce memory usage
	// only 3 elements are needed because Fibonacci only depends on last 2
	// but a size of 4 is chosen so that we can replace the use of 
	// the modulo operator (%) since division is expensive
	unsigned long long fib[4];
	
	fib[0] = 0;
	fib[1] = 1;
	
	unsigned long long i;
	for (i = 2; i < term+1; i++) {
		fib[i&3] = fib[(i-1)&3] + fib[(i-2)&3];
	// instead of modulo we can use bitwise AND (& (size-1)) since our
	// array is size power of 2
	}

	printf("Fibonacci term #%d: %llu\n", term, fib[term&3]);

	return fib[term&3];
}
