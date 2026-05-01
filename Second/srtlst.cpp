#include"SortedList.h"
#include<iostream>

using namespace std;

sorted_list::~sorted_list() {
	delete[] pA;
	cap = 0;
	count = 0;
}

void sorted_list::clear() {
	if (pA != nullptr) delete[] pA;
	pA = nullptr;
	cap = 0;
	count = 0;
}

void sorted_list::alloc(int n) {
	if (cap >= count + n) return;

	while (cap < count + n) {
		if (!cap) cap = 1;
		else cap *= 2;
	}

	element* tmp = new element[cap];
	for (int i = 0; i < count; i++) {
		*(tmp + i) = *(pA + i);
	}

	delete[] pA;
	pA = tmp;
}

void sorted_list::insert(element num) {
	alloc(1);

	element temp = num;
	int i;
	for (i = 0; i < count; i++) {
		if (!(pA[i] == num)) return;
		if ((pA[i] == num) > 0) {
			temp = pA[i];
			pA[i] = num;
			i++;
			break;
		}
	}

	while (i < count) {
		swap(temp, pA[i++]);
	}
	pA[count++] = temp;
}

element& sorted_list::operator[](const unsigned n) const {
	if (n >= count) { std::cout << "Out of range"; std::terminate(); }
	return pA[n];
}