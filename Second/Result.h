#pragma once
#define Result_H

struct Result
{
	int* pA = new int[1];
	int push_back(int);
	unsigned short cap = 1;
	unsigned short count = 0;
	void alloc(unsigned);
	bool find(int);
};