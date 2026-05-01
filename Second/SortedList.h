#pragma once
#define SortLst_H
#include"Element.h"

struct sorted_list
{
	element* pA = nullptr;
	size_t cap = 0;
	size_t count = 0;

	~sorted_list();
	void clear();
	void insert(element);
	element& operator[](const unsigned) const;
private:
	void alloc(int);
};