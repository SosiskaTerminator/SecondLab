#include"block.h"
#include"constants.h"
#include<iostream>

Block::Block() {
	cap = 1;
	p = new String[cap];
}

Block::Block(int n) {
	setcap(n);
	p = new String[cap];
}

Block::~Block() {
	if (p != nullptr) delete[] p;
	p = nullptr;
	cap = 0;
	count = 0;
}

void Block::clear(){
	count = 0;
}

std::ostream& operator<<(std::ostream& os, Block& ex) {
	os << "Block{строки:\n";
	for (int i = 0; i < ex.count; i++) {
		os << "\t" << ex.p[i] << "\n";
	}
	os << "объём: " << ex.cap << ", кол-во: " << ex.count << " }";
	return os;
}

String Block::getstring(unsigned n) const {
	if (p == nullptr) { std::cout << "Массив пуст" << std::endl; return NULL; }
	else if (n < 0 || n > count) { std::cout << "Выход за пределы массива" << std::endl; return NULL; }
	else return p[n];
}

void Block::alloc(unsigned n) {
	if (cap >= count + n) return;

	while (cap < count + n) {
		if (!cap) cap = 1;
		else cap *= 2;
	}

	String* tmp = new String[cap];
	for (int i = 0; i < count; i++) {
		*(tmp + i) = *(p + i);
	}

	delete[] p;
	p = tmp;
}

void Block::setcap(int n) {
	if (n < 0) { std::cout << "Отрицательное значение длины. Выставлено значение 0." << std::endl; cap = 0; }
	else if (n > size_of_block) { std::cout << "Значение слишком большое. Выставлено значение size_of_block." << std::endl; cap = size_of_block; }
	else cap = n;
}

int Block::push_back(String& s) {
	if (count >= size_of_block) return -1;
	alloc(1);
	p[count++] = s;
	return 0;
}

unsigned short Block::getcap() const {
	return cap;
}

unsigned short Block::getcount() const {
	return count;
}