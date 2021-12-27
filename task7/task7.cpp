#include <iostream>
#include <cstring>
using namespace std;

bool IsPalindrome(char* word,int f,int g) {
	int k = g - f + 1;
	for (int i = f; i < f+ k/2 ; i++) {
		if (word[i] != word[k - 1 - i]) {
			return false;
		}
	}
	return true;
}

int max(int x, int y) {
	return (x > y) ? x : y;
}
int main() {
	char* word = new char [106];
	cin.getline(word, 106);
	int n = strlen(word);
	int z= -1;
	int Max = -1;
	for (int i = 0; i < n; i++) {
		for (int j =i + 1; j < n; j++) {

			if (!IsPalindrome(word,i,j)) {
				z = j - i + 1;
			}
			Max = max(Max, z);
		}
	}
	cout << Max;

	delete[] word;
}