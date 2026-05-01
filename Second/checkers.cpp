#include"checkers.h"

bool is_cap(char c) {
	return ('A' <= c && c <= 'Z');
}

bool is_end(char c) {
	return (c == '.' || c == '!' || c == '?');
}