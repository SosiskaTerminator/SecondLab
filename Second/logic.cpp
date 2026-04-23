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

void readfile(sorted_list& spaces, sorted_list& starts, sorted_list& ends) {
	fstream file("text.txt", ios::in);
	if (!file.is_open()) { std::cout << "ќшибка отрыти€ файла." << endl; return; }
	file.unsetf(std::ios::skipws);
	char tmp;
	int flag;
	unsigned arr[size_of_block], i = 0, номер_итерации = 0, номер_блочного_считывани€ = 0, next_block = 0, eof = -1;

	Block bl;
	String s;

	file >> tmp;
	if (file.eof()) { std::cout << "‘айл пуст"; }

	while (eof == -1) {
		file.seekg(next_block, file.beg);
	считывание_строки:
		do {
			if (i >= size_of_block) break;
			if (!номер_итерации) { arr[i++] = file.tellg(); }
			else {
				if (arr[i] == -1) break;
				if (i + 1 < size_of_block && arr[i] + length_of_string * номер_итерации >= arr[i + 1]) {
					i++;
					continue;
				}
				else if (i + 1 == size_of_block && arr[i] + length_of_string * номер_итерации >= next_block) break;
				else {
					file.seekg(arr[i++] + length_of_string * номер_итерации, file.beg);
				}
			}
			file >> tmp;
			while (tmp != '\n' && s.push_back(tmp) != -1 && !file.eof()) {
				file >> tmp;
			}
			if (file.eof()) {
				file.clear();
				eof = file.tellg();
				break;
			}
			flag = bl.push_back(s);
			s.clear();
			if (!номер_итерации) { skip_to_n(&file); if (i >= size_of_block) { if (file.eof()) file.clear(); next_block = file.tellg(); } }
		} while (flag != -1);
		if (!bl.getcount()) goto выход;
		file.clear();
		std::cout << bl << endl;
		for (int j = 0; j < i; j++) {
			if (arr[j] == -1) break;
			std::cout << arr[j] + length_of_string * номер_итерации << ' ';
		}
		std::cout << "\n===================================================================" << endl;

		flag = 0; i = 0; номер_итерации++;
		bl.clear();

		goto считывание_строки;
	выход:
		std::cout << "—трока считана" << endl;
		flag = 0; i = 0; номер_итерации = 0;
		bl.clear();
		номер_блочного_считывани€++;
	}
}