#ifndef String_H
#define String_H
#include<iostream>
#include"constants.h"

class String
{
private:
	char p[length_of_string];
	unsigned short count = 0;
	int line = 0;
	unsigned start = 0;
public:
	String();
	friend std::ostream& operator<<(std::ostream& os, const String& p);
	bool operator==(const String& other);
	void setline(int);
	int getline();
	void setstart(unsigned);
	unsigned getstart();
	unsigned short getcount() const;
	char getchar(unsigned) const;
	int push_back(char);
	bool find(char*, int) const;
	void clear();
};
#endif