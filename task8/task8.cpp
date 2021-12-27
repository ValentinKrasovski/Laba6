#include <iostream>
#include <string>
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

bool left(string str1, string str2, int ind) {
	for (; str2.length() > 0 && ind >= 0 && str1[ind] == str2[0]; ind--){
		str2 = str2.substr(1);
	}
	if (str2.length() == 0){
		return true;
	} else {
		return false;
	}
}

bool write(string str1, string str2, int ind) {
	int l1 = str1.length();
	int cind = ind;

	for (cind; str1[cind] == str2[cind - ind] && cind < l1; cind++) {
		if (left(str1, str2.substr(cind - ind), cind)) {
			return true;
		}
	}
	return false;
}

bool writeout(string str1, string str2) {
	int l1 = str1.length();
	for (int i = 0; i < l1; i++) {
		if (write(str1, str2, i)) {
			return true;
		}
	}
	return false;
}

int main() {
	
	int n = element();
	
	for (int i = 0; i < n;i++) {
		string str1, str2;
		getline(cin, str1);
		getline(cin, str2);

		if (writeout(str1, str2)) {
			cout << "YES"<< endl;
		} else {
			cout << "NO"<< endl;
		}
	}
	return 0;
}