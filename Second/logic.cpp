#include"logic.h"
#include"constants.h"
#include"checkers.h"
#include"Block.h"
#include<fstream>
#include<iostream>

using namespace std;

void skip_to_n(fstream* file) {
	char tmp = '\0';

	while (tmp != '\n') {
		if (file->eof()) return;
		*file >> tmp;
	}
}

void readfile(sorted_list spaces, sorted_list starts, sorted_list ends) {
	fstream file("text.txt", ios::in);
	if (!file.is_open()) { cout << "Ошибка отрытия файла." << endl; return; }
	file.unsetf(std::ios::skipws);

	Block bl;
	String str;

	int arr[size_of_block], next_block, iter = 0, occupancy = 0;
	bool flag = true;

	while (flag) {


		char tmp = '\0';

		while (tmp != '\n' && !file.eof() && !occupancy) {
			if (tmp != '\0') occupancy = str.push_back(tmp);

			file >> tmp;
		}
	}
}

