#include <iostream>
#include <string>
using namespace std;

int main(){

	string str;
	getline(cin, str);
	cout << endl;

	int i = 0;
	double sum = 0;
	int l = str.length();
	
	while (i < l)
	{
		int k = 0;
		char s[100]{};
		while (str[i] >= 48 && str[i] <= 57) {
			s[k] = str[i];
			k++;
			i++;
		}
		if (!k) {
			i++;
		}
		sum += atoi(s); // преобразование в int
	}
	cout << sum << endl;
	return 0;
}
