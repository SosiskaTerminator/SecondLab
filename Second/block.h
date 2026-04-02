#ifndef Block_H
#define Block_H
#include<iostream>
#include"string.h"

class Block 
{
private:
	String* p;
	unsigned short cap;
	unsigned short count = 0;
	void alloc(unsigned);
public:
	Block();
	Block(int);
	~Block();
	friend std::ostream& operator<<(std::ostream&, Block&);
	String getstring(unsigned) const;
	unsigned short getcap() const;
	unsigned short getcount() const;
	void setcap(int);
	int push_back(String&);
	void clear();
};
#endif