#ifndef String_H
#define String_H
#include<iostream>

class String
{
private:
	char* p;
	unsigned short cap;
	unsigned short count = 0;
	void alloc(unsigned);
public:
	String();
	String(int);
	~String();
	friend std::ostream& operator<<(std::ostream& os, const String& p);
	String& operator=(const String& other);
	void setcap(int);
	unsigned short getcount() const;
	unsigned short getcap() const;
	int push_back(char);
	char getchar(unsigned) const;
	bool find(char*, int) const;
	void clear();
};
#endif