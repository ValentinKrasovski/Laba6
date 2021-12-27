#include <iostream>
#include <cstdio>
using namespace std;

//проверка на ввод

int elementn() {
	int n;
	bool isNotCorrect;
	do {
		isNotCorrect = false;
		cin >> n;
		if (cin.fail() || n>80) {
			cin.clear();
			cin.ignore(66666, '\n');
			cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
			isNotCorrect = true;
		}
	} while (isNotCorrect);
	cin.ignore(66666, '\n');
	return n;
}

//функция минимума
int min(int x, int y) {
	return x > y ? y : x;
}

char element() {
	char n;
	bool isNotCorrect;
	do {
		isNotCorrect = false;
		cin >> n;
		if (cin.fail() ||( n!='1' && n != '0')) {
			cin.clear();
			cin.ignore(66666, '\n');
			cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
			isNotCorrect = true;
		}
	} while (isNotCorrect);
	//cin.ignore(66666, '\n');
	return n;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер строки";
	int n = elementn();
	char str[80];
	cout << "Введите строку";
	for (int i = 0; i < n; i++) {
		str[i] = element();
	}

	int i = 0;
	int Min0 = 80;
	int Min1 = 80;
	while (str[i] != '\0') {
	    int z = 1;
		if (str[i] == '0') {
			while (str[i] == str[i + 1]) {
				z++;
				i++;
			}
			Min0 = min(z, Min0);
			
		} 
			i++;

	}

	i = 0;
	while (str[i] != '\0') {
		int z = 1;
		if (str[i] == '1') {
			while (str[i] == str[i + 1]) {
				z++;
				i++;
			}
			Min1 = min(z, Min1);
		} 
			i++;
		
	}
	cout << Min0<<endl;
	cout << Min1<<endl;
	
	if (Min0 < Min1) {
		for (i = 0; i < Min0; i++) {
			cout << "0 ";
		}
	} else {
		for (i = 0; i < Min1; i++) {
			cout << "1 ";
		}
	}

	return 0;
}

