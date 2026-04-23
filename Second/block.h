#ifndef Block_H
#define Block_H
#include<iostream>
#include"String.h"
#include"constants.h"

class Block 
{
private:
	String p[size_of_block];
	//unsigned short cap;
	unsigned short count = 0;
	//void alloc(unsigned);
public:
	Block();
	//~Block();
	friend std::ostream& operator<<(std::ostream&, Block&);
	String getstring(unsigned) const;
	//unsigned short getcap() const;
	unsigned short getcount() const;
	//void setcap(int);
	int push_back(String&);
	void clear();
	bool check();
};
#endif