#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int element() {
	int n;
	bool isNotCorrect;
	do {
		isNotCorrect = false;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(66666, '\n');
			cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
			isNotCorrect = true;
		}
	} while (isNotCorrect);
	//cin.ignore(66666, '\n');
	return n;
}

int elementm() {
	int n;
	bool isNotCorrect;
	do {
		isNotCorrect = false;
		cin >> n;
		if (cin.fail() || n > pow(10,4)) {
			cin.clear();
			cin.ignore(66666, '\n');
			cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
			isNotCorrect = true;
		}
	} while (isNotCorrect);
	cin.ignore(66666, '\n');
	return n;
}


int main() {
	setlocale(LC_ALL, "rus");
	int t = elementm();
	int* p = new int[t];
	for (int i = 0; i < t; i++) {

		int L = element();
		int m = elementm();
		string S1;
		getline(cin, S1);
		string S2;
		getline(cin, S2);



		int l1 = S1.length();
		int l2 = S2.length();
		int d = abs(L - (l1 + l2));
		int z;
		int k;
		if (L > l1 + l2) {
			z = 2 * powl(26, (L - (l1 + l2)));
			k = z % m;
		}
		else {
			if (S1.compare(l1 - d, l1, S2, 0, d)) {//if they are different
				k = 0;
			}
			else {
				k = 1;
			}
		}
		p[i] = k;
		cout << endl;
	}
	
	for (int i = 0; i < t; i++) {
		cout << p[i]<<endl;
	}

	return 0;
}
