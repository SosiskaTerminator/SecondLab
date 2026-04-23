#include "String.h"
#include "constants.h"
#include<iostream>

String::String() {
	//cap = 1;
	//p = new char[1];
}

//String::~String() {
//	if (p != nullptr) delete[] p;
//	p = nullptr;
//	cap = 0;
//	count = 0;
//}

std::ostream& operator<<(std::ostream& os, const String& p) {
	os << "String{массив: #";
	for (int i = 0; i < p.count; i++) {
		os << p.p[i];
	}
	os << "#, кол-во элементов: " << p.count << "}";
	return os;
}

bool String::operator==(const String& other) {
	if (count == other.count) {
		for (int i = 0; i < count; i++) {
			if (p[i] != other.p[i]) return false;
		}
		return true;
	}
	else return false;
}

//void String::setcap(int n) {
//	if (n < 0) { cap = 0; std::cout << "Значение меньше нуля. Объем выставлен 0." << std::endl; }
//	if (n > length_of_string) { cap = length_of_string; std::cout << "Значение больше разрешённого. Объем выставлен максимально разрешённым." << std::endl; }
//	else cap = n;
//}

unsigned short String::getcount() const {
	return count;
}

//unsigned short String::getcap() const {
//	return cap;
//}

int String::push_back(char c) {
	if (count >= length_of_string) return -1;
	//alloc(1);
	p[count] = c;
	count++;

	return 0;
}

char String::getchar(unsigned n) const {
	if (count != 0 && n < length_of_string) return p[n];
	else if (count != 0) { std::cout << "Выход за границы." << std::endl; return '\0'; }
	else { std::cout << "Массив не инициализирован" << std::endl; return '\0'; }
}

//void String::alloc(unsigned n) {
//	if (cap >= count + n) return;
//
//	while (cap < count + n) {
//		if (!cap) cap = 1;
//		else cap *= 2;
//	}
//
//	char* tmp = new char[cap];
//	for (int i = 0; i < count; i++) {
//		*(tmp + i) = *(p + i);
//	}
//
//	delete[] p;
//	p = tmp;
//}

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