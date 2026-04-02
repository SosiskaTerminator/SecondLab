#include"string.h"
#include"block.h"
#include"logic.h"
#include"constants.h"
#include"Result.h"
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

bool is_capitaly(char c) {
	return ('A' <= c && c <= 'Z');
}

bool is_end_of_sentance(char c) {
	return (c == '.' || c == '!' || c == '?');
}

int find(unsigned arr[size_of_block], unsigned n) {
	for (int i = 0; i < size_of_block; i++) {
		if (arr[i] == n) return i + 1;
	}

	return NULL;
}

void process(Block* bl, unsigned arr[size_of_block], fstream& f, Result res) {
	for (int i = 0; i < bl->getcount(); i++) {
		String s = bl->getstring(i);

		int cnt = 0;
		bool был_конец = false;

		for (int j = 0; j < s.getcount(); j++) {
			был_конец = is_end_of_sentance(s.getchar(j));
			if (был_конец) {
				if (s.getchar(j) == ' ') cnt++;
				else if (cnt == 5 && is_capitaly(j)) res.push_back(size_of_block * s.getстарт(2) + find(arr, s.getстарт(0)));
				else { был_конец = false; cnt = 0; }
			}
		}

		if (был_конец) {
			char c = '\0';
			while (true) {
				f >> c;

				if (f.eof() || (cnt != 5 && c != ' ')) return;

				if (cnt != 5 && c == ' ') cnt++;
				else if (cnt == 5 && is_capitaly(c)) res.push_back(size_of_block * s.getстарт(2) + find(arr, s.getстарт(0)));
				else return;
			}
		}
	}
}

void skip_to_n(fstream* file) {
	char tmp = '\0';

	while (tmp != '\n') {
		if (file->eof()) return;
		*file >> tmp;
	}
}

Result readfile() {
	fstream file("text.txt", ios::in);
	if (!file.is_open()) { std::cout << "Ошибка отрытия файла." << endl; return; }
	file.unsetf(std::ios::skipws);
	char tmp;
	int flag;
	unsigned arr[size_of_block], i = 0, номер_итерации = 0, номер_блочного_считывания = 0, next_block = 0, eof = -1;
	Result res;

	Block* bl = new Block();
	String* s = new String();

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
			s->setстарт(arr[i - 1], arr[i - 1] + length_of_string * номер_итерации, номер_блочного_считывания);
			file >> tmp;
			while (tmp != '\n' && s->push_back(tmp) != -1 && !file.eof()) {
				file >> tmp;
			}
			if (file.eof()) {
				file.clear();
				eof = file.tellg();
				break;
			}
			flag = bl->push_back(*s);
			delete s;
			s = new String();
			if (!номер_итерации) { skip_to_n(&file); if (i >= size_of_block) { if (file.eof()) file.clear(); next_block = file.tellg(); } }
		} while (flag != -1);
		if (!bl->getcount()) goto выход;
		process(bl, arr, file, res);
		file.clear();
		std::cout << *bl << endl;
		for (int j = 0; j < i; j++) {
			if (arr[j] == -1) break;
			std::cout << arr[j] + length_of_string * номер_итерации << ' ';
		}
		std::cout << "\n===================================================================" << endl;
		
		flag = 0; i = 0; номер_итерации++;
		delete bl;
		bl = new Block;

		goto считывание_строки;
	выход:
		std::cout << "Строка считана" << endl;
		flag = 0; i = 0; номер_итерации = 0;
		delete bl;
		bl = new Block;
		номер_блочного_считывания++;
	}

	return res;
}