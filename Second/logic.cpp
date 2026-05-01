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

void parsing(Block bl, sorted_list(&lists)[3]) {
	for (int i = 0; i < bl.getcount(); i++) {
		String tmp = bl.getstring(i);
		element el(tmp.getstart(), tmp.getline());

		for (int j = 0; j < tmp.getcount(); j++) {
			if (tmp.getchar(j) == ' ') lists[0].insert(el);
			if (is_end(tmp.getchar(j))) lists[1].insert(el);
			if (is_cap(tmp.getchar(j))) lists[2].insert(el);

			el.position++;
		}
	}
}

void readfile(sorted_list (&lists)[3]) {
	fstream file("text.txt", ios::in);
	if (!file.is_open()) { std::cout << "Ошибка отрытия файла." << endl; return; }
	file.unsetf(std::ios::skipws);
	char tmp;
	int flag;
	unsigned arr[size_of_block], i = 0, номер_итерации = 0, номер_блочного_считывания = 0, next_block = 0, eof = -1;

	Block bl;
	String s;

	file >> tmp;
	if (file.eof()) { std::cout << "Файл пуст"; }

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
			if (tmp != '\n') {
				s.setstart(arr[i - 1] + length_of_string * номер_итерации);
				while (tmp != '\n' && s.push_back(tmp) != -1 && !file.eof()) {
					file >> tmp;
				}
				s.setline(i + size_of_block * номер_блочного_считывания);
				flag = bl.push_back(s);
				s.clear();
			}

			if (file.eof()) {
				file.clear();
				eof = file.tellg();
				break;
			}

			/*flag = bl.push_back(s);
			s.clear();*/

			if (!номер_итерации) { if (tmp != '\n') skip_to_n(&file); if (i >= size_of_block) { if (file.eof()) file.clear(); next_block = file.tellg(); } }
		} while (flag != -1);

		if (!bl.getcount()) goto выход;
		file.clear();

		cout << bl << endl;

		parsing(bl, lists);

		for (int j = 0; j < i; j++) {
			if (arr[j] == -1) break;
			std::cout << arr[j] + length_of_string * номер_итерации << ' ';
		}
		cout << "\n===================================================================" << endl;

		flag = 0; i = 0; номер_итерации++;
		bl.clear();

		goto считывание_строки;
	выход:
		std::cout << "Строка считана" << endl;
		flag = 0; i = 0; номер_итерации = 0;
		bl.clear();
		номер_блочного_считывания++;
	}
}

void getlines(sorted_list(&lists)[3]) {
	int start_line = 0, end_line = 0, pos = 0;
	unsigned i_space = 0, i_end = 0, i_start = 0;
	bool flag = true;

	while (flag) {
		int count = 1;
		flag = true;

		while (count != 5) {
			if (i_space + 1 == lists[0].count) { flag = false; break; }
			if (lists[0][i_space].line <= i_end) { i_space++; continue; }

			if (lists[0][i_space].position + 1 == lists[0][i_space + 1].position) {
				if (count == 1) pos = lists[0][i_space].position;
				count++;
			}
			else {
				count = 1;
			}

			i_space++;
		}

		if (count == 5) {
			while (i_start != lists[2].count) {
				if (lists[2][i_start].position == pos + 5) { start_line = lists[2][i_start++].line; break; }
				i_start++;
				if (i_start == lists[2].count) flag = false;
			}

			while (i_end != lists[1].count && flag) {
				if (lists[1][i_end].position > pos) { end_line = lists[1][i_end++].line; break; }
				i_end++;
				if (i_end == lists[1].count) flag = false;
			}

			if (flag) {
				for (int i = start_line; i <= end_line; i++) {
					cout << i << ' ';
				}
			}
		}
	}
}