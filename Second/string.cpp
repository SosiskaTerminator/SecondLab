#include "String.h"
#include "constants.h"
#include<iostream>

String::String() {
	//cap = 1;
	//p = new char[1];
}

std::ostream& operator<<(std::ostream& os, const String& p) {
	os << "String{массив: #";
	for (int i = 0; i < p.count; i++) {
		os << p.p[i];
	}
	os << "#, кол-во элементов: " << p.count << ", номер строки: " << p.line << "}";
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

unsigned short String::getcount() const {
	return count;
}

int String::push_back(char c) {
	if (count >= length_of_string) return -1;
	p[count] = c;
	count++;

	return 0;
}

char String::getchar(unsigned n) const {
	if (count != 0 && n < length_of_string) return p[n];
	else if (count != 0) { std::cout << "Выход за границы." << std::endl; return '\0'; }
	else { std::cout << "Массив не инициализирован" << std::endl; return '\0'; }
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

void String::setline(int n) {
	line = n;
}

int String::getline() {
	return line;
}

void String::setstart(unsigned n) {
	start = n;
}

unsigned String::getstart() {
	return start;
}