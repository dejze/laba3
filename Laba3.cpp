#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


string Rus_cons = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //Массив с буквами
string symbols = "!@#$%^&*(){}[]<>_+1234567890-=!\"\'№%?*:;|\\/`~"; //Массив символов

bool contain(const string& s, const char& a)//Возвращает 1 или 0, если в переданной строке есть или нет переданный символ
{
	for (int j = 0; j < s.size(); j++) //Проходим по переданной строке
		if (a == s[j]) //Сравниваем текущий символ с переданным
			return true; //Если они равны => переданный символ есть в переданной строке
	return false; //Мы прошли всю строку, но не нашли переданный символ => его нет в строке
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Чтобы посчитать кол-во букв введите сообщение(пожалуйста вводите без заглавных букв):" << endl;

	string in;
	int cons;
	cons = 0;
	getline(cin, in);

	std::unordered_map<char, unsigned int> counts;
	std::unordered_map<char, unsigned int> counts2;
	std::for_each(std::begin(in), std::end(in), [&counts](char c) {
		counts[c]++;
		});
	std::for_each(std::begin(Rus_cons), std::end(Rus_cons), [&counts, &counts2](char c) {
		const auto& it = counts.find(c);
		if (it != counts.end()) counts2.insert(*it);
		});

	for (auto& kv : counts2)
	{
		std::cout << kv.first << ": " << kv.second << "\n";
	}

	for (int i = 0; i < in.size(); i++) //Проходим циклом от первого до последнего символа в строке
		if (!contain(symbols, in[i])) //Если текущий символ буква
		{
			if (contain(Rus_cons, in[i])) //Если буква из алфавита
				cons++;
		}


	//Вывод результат
	cout << "Всего в строке \"" << in << "\" " << cons << " букв(ы) " << endl;
	system("pause");
	return 0;
}