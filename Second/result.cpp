#include"Result.h"

void Result::alloc(unsigned n) {
	if (cap >= count + n) return;

	while (cap < count + n) {
		if (!cap) cap = 1;
		else cap *= 2;
	}

	int* tmp = new int[cap];
	for (int i = 0; i < count; i++) {
		*(tmp + i) = *(pA + i);
	}

	delete[] pA;
	pA = tmp;
}

int Result::push_back(int c) {
	alloc(1);
	if (!find(c)) pA[count++] = c;

	return 0;
}

bool Result::find(int n) {
	for (int i = 0; i < count; i++) {
		if (*(pA + i) == n) return true;
	}

	return false;
}