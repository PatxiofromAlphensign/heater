#include<thread.h>
int compute_high(int size) {
	int b;
	if(size>size*2) return b;
	b = compute_high(size+1);
	return b;
}
