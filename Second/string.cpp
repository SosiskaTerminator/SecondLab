#include "string.h"
#include "constants.h"
#include<iostream>

String::String() {
	cap = 1;
	p = new char[1];
}

String::String(int n) {
	setcap(n);
	p = new char[cap];
}

String::~String() {
	if (p != nullptr) delete[] p;
	p = nullptr;
	cap = 0;
	count = 0;
}

std::ostream& operator<<(std::ostream& os, const String& p) {
	os << "String{массив: #";
	for (int i = 0; i < p.count; i++) {
		os << p.p[i];
	}
	os << "#, обьем: " << p.cap << ", кол-во элементов: " << p.count << "}";
	return os;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] p;
		count = other.count;
		cap = other.cap;
		p = new char[cap];
		for (int i = 0; i < count; i++) p[i] = other.p[i];
	}
	return *this;
}

void String::setcap(int n) {
	if (n < 0) { cap = 0; std::cout << "Значение меньше нуля. Объем выставлен 0." << std::endl; }
	if (n > length_of_string) { cap = length_of_string; std::cout << "Значение больше разрешённого. Объем выставлен максимально разрешённым." << std::endl; }
	else cap = n;
}

unsigned short String::getcount() const {
	return count;
}

unsigned short String::getcap() const {
	return cap;
}

int String::push_back(char c) {
	if (count >= length_of_string) return -1;
	alloc(1);
	p[count] = c;
	count++;

	return 0;
}

char String::getchar(unsigned n) const {
	if (p != nullptr && n >= 0 && n < cap) return *(p + n);
	else if (p != nullptr) { std::cout << "Выход за границы." << std::endl; return '\0'; }
	else { std::cout << "Массив не инициализирован" << std::endl; return '\0'; }
}

void String::alloc(unsigned n) {
	if (cap >= count + n) return;

	while (cap < count + n) {
		if (!cap) cap = 1;
		else cap *= 2;
	}

	char* tmp = new char[cap];
	for (int i = 0; i < count; i++) {
		*(tmp + i) = *(p + i);
	}

	delete[] p;
	p = tmp;
}

bool String::find(char* s, int size) const {
	int j = 0;

	for (int i = 0; i < count; i++) {
		char a = p[i], b = s[j];

		if (p[i] == s[j]) j++;
		else if (p[i] != s[j]) { i -= j; j = 0; }
		if (j == size) return true;
	}

	return false;
}

void String::clear() {
	count = 0;
}