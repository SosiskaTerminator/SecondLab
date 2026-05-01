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

	sorted_list lists[3];//1-пробелы, 2-концы, 3-начала

	readfile(lists);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < lists[i].count; j++) {
			cout << lists[i][j] << ' ';
		}

		cout << endl;
		cout << "+++++++++++++++++++++++++++" << endl;
	}

	cout << endl;

	getlines(lists);

	delete lists;
}