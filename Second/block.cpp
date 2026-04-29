#include"Block.h"
#include"constants.h"
#include<iostream>

Block::Block() {
	/*cap = 1;
	p = new String[cap];*/
}

void Block::clear(){
	count = 0;
}

std::ostream& operator<<(std::ostream& os, Block& ex) {
	os << "Block{строки:\n";
	for (int i = 0; i < ex.count; i++) {
		os << "\t" << ex.p[i] << "\n";
	}
	os << ", кол-во: " << ex.count << " }";
	return os;
}

String Block::getstring(unsigned n) const {
	if (count == 0) { std::cout << "Массив пуст" << std::endl; return String(); }
	else if (n < 0 || n > count) { std::cout << "Выход за пределы массива" << std::endl; return String(); }
	else return p[n];
}

int Block::push_back(String& s) {
	if (count >= size_of_block) return -1;
	//alloc(1);
	p[count++] = s;
	return 0;
}

unsigned short Block::getcount() const {
	return count;
}

bool Block::check() {
	int cnt = 0;

	for (int i = 0; i < count; i++) {
		if (!p[i].getcount()) cnt++;
	}

	return (cnt == count) ? false : true;
}