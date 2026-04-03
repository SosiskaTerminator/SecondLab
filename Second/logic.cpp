#include"logic.h"
#include"constants.h"
#include"checkers.h"
#include<fstream>
#include<iomanip>

using namespace std;

void process(Block &bl, int (&result)[1000], int iter) {
	static int number_of_line = 1, count = 0;
	bool was_end = false;
	int cnt = 0, было = number_of_line;


	for (int i = 0; i < bl.getcount(); i++) {
		String s = bl.getstring(i);

		if (s == String()) continue;

		for (int j = 0; j < s.getcount(); j++) {
			if (is_end(s.getchar(j))) { was_end = true; continue; }

			if (was_end) {
				if (cnt == 5 && is_cap(s.getchar(j))) { result[count] = number_of_line; cout << number_of_line << endl; break; }
				else { cnt = 0; was_end = false; }
				if (s.getchar(j) == ' ') cnt++;
			}
		}
	}

	if (iter != 0) number_of_line = было;
}

void skip_to_n(fstream* file) {
	char tmp = '\0';

	while (tmp != '\n') {
		if (file->eof()) return;
		*file >> tmp;
	}
}

void readfile() {
	fstream file("text.txt", ios::in);
	if (!file.is_open()) { cout << "ќшибка отрыти€ файла." << endl; return; }
	file.unsetf(std::ios::skipws);
	char tmp;
	int flag;
	int arr[size_of_block], i = 0, номер_итерации = 0, next_block = 0, eof = 1;
	int result[1000];

	Block* bl = new Block();
	String* s = new String();

	file >> tmp;
	if (file.eof()) { cout << "‘айл пуст"; }

	while (eof == 1) {
		file.seekg(next_block, file.beg);
	считывание_строки:
		do {
			if (i >= size_of_block) break;
			if (!номер_итерации) { arr[i++] = file.tellg(); }
			else {
				if (arr[i] == -1) break;
				if (i + 1 < size_of_block && arr[i] + length_of_string * номер_итерации >= arr[i + 1]) {
					bl->push_back(*s);
					i++;
					continue;
				}
				else if (i + 1 == size_of_block && arr[i] + length_of_string * номер_итерации >= next_block) break;
				else {
					file.seekg(arr[i++] + length_of_string * номер_итерации, file.beg);
				}
			}

			file.get(tmp);
			while (tmp != '\n' && s->push_back(tmp) != -1 && !file.eof()) {
				file.get(tmp);
			}

			if (tmp == '\n') s->setend(true);

			if (file.eof()) {
				file.clear();
				eof = file.tellg();
				break;
			}

			flag = bl->push_back(*s);
			delete s;
			s = new String();
			if (!номер_итерации && tmp != '\n') { skip_to_n(&file); if (i >= size_of_block) {  next_block = file.tellg(); } }
		} while (flag != -1 && eof == 1);

		if (!bl->check()) goto выход;

		//process(*bl, result, номер_итерации);

		cout << *bl << endl;
		cout << "»ндексы начала строк: ";
		for (int j = 0; j < i; j++) {
			if (arr[j] == -1) break;
			cout << arr[j] + length_of_string * номер_итерации << ' ';
		}
		cout << "\n===================================================================" << endl;
		
		flag = 0; i = 0; номер_итерации++;
		delete bl;
		bl = new Block;

		goto считывание_строки;
	выход:
		cout << "—трока считана" << endl;
		flag = 0; i = 0; номер_итерации = 0;
		delete bl;
		bl = new Block;
	}
}