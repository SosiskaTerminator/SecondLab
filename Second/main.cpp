#include<iostream>
#include"logic.h"
#include"SortedList.h"

using namespace std;

void print(sorted_list& lst) {
	for (int i = 0; i < lst.count; i++) {
		cout << lst[i] << ' ';
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	sorted_list lst_of_space,
				lst_of_end,
				lst_of_start;

	readfile(lst_of_space, lst_of_start, lst_of_end);
}