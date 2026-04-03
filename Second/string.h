#ifndef String_H
#define String_H
#include<iostream>

class String
{
private:
	char* p;
	unsigned short cap;
	unsigned short count = 0;
	bool был_конец_строки = false;
	void alloc(unsigned);
public:
	String();
	String(int);
	~String();
	friend std::ostream& operator<<(std::ostream& os, const String& p);
	String& operator=(const String& other);
	bool operator==(const String& other);
	void setcap(int);
	void setend(bool);
	bool getend() const;
	unsigned short getcount() const;
	unsigned short getcap() const;
	char getchar(unsigned) const;
	int push_back(char);
	bool find(char*, int) const;
	void clear();
};
#endif