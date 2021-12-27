#include <iostream>
#include <cstring>
using namespace std;

int fact(int z) {
	if (z == 0) {
		return 1;
	}
	if (z == 1) {
		return 1;
	}
	return z * fact(z - 1);
}

int main() {
	char* word = new char[15];
	cin.getline(word, 14);
	int n = strlen(word);
	cout << n<< endl;
	int search=fact(n);
	cout << search<< endl;

	for (int i = 0; i < n; i++) {
		if (word[i] == '.') {
			continue;
		}
		int z = 1;
		for (int j = i + 1; j < n; j++) {
			//f = searcht(word, i);
			if (word[i] == word[j]) {
				word[j] = '.';
				z++;
			}
			cout << fact(z)<<endl;
		}
		search = search / fact(z);
		cout << word<<endl;
	}
	cout << search;
	delete[] word;

	return 0;
}