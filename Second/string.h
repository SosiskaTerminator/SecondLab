#ifndef String_H
#define String_H
#include<iostream>
#include"constants.h"

class String
{
private:
	char p[length_of_string];
	//unsigned short cap = length_of_string;
	unsigned short count = 0;
	//void alloc(unsigned);
public:
	String();
	//~String();
	friend std::ostream& operator<<(std::ostream& os, const String& p);
	bool operator==(const String& other);
	//void setcap(int);
	unsigned short getcount() const;
	//unsigned short getcap() const;
	char getchar(unsigned) const;
	int push_back(char);
	bool find(char*, int) const;
	void clear();
};
#endif