#include<iostream>
using namespace std;

int main()
{
    char* str = new char[100];
    cin.getline(str, 100);
    int code;
    char el;

    cout << endl;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != str[i + 1])
            cout << str[i];
        else {
            int z=1;
            int j = i;
            while (str[j] == str[j + 1]) {
                z++;
                j++;
            }
            code = str[i];
            cout << "255," << code << "," << z;
            i += z-1;
        }
    }
    delete[] str;
}