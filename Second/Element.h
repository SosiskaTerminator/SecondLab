#pragma once
#define El_H
#include<iostream>

struct element
{
	int position;
	int line;

	element();
	element(int, int);
	int operator==(const element&);
	element& operator=(const element&) noexcept;
	friend std::ostream& operator<<(std::ostream&, element&);
};