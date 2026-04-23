#include"Element.h"

element::element() {
	position = 0;
	line = 0;
}

element::element(int a, int b) {
	position = a;
	line = b;
}

int element::operator==(const element& other) {
	if (position == other.position && line == other.line) return 0;
	if (position > other.position) return 1;
	else return -1;
}

element& element::operator=(const element& other) noexcept {
	position = other.position;
	line = other.line;
	
	return *this;
}

std::ostream& operator<<(std::ostream& os, element& el) {
	os << '[' << el.position << ", " << el.line << ']';
	return os;
}