#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int strl = 3;
    char* str = (char*)malloc(strl * sizeof(char));
    str[0] = ' ';
    cout << "¬ведите строку : ";

    for (int l = 1; '\n' - (str[l] = getchar()); l++) {
        str = (char*)realloc(str, strl++ * sizeof(char));
    }
    int word_l = 2;
    char* nword = (char*)malloc(word_l * sizeof(char));
    cout << "¬ведите новое слово : ";

    for (int l = 0; '\n' - (nword[l] = getchar()); l++) {
        nword = (char*)realloc(nword, word_l++ * sizeof(char));
    }
    int l;
    cout << "¬ведите длину : \n";
    cin >> l;
    int res_l = 2;
    char* res = (char*)malloc(res_l * sizeof(char));
    int space;
    int sh_res = 0;
    for (int i = 0; i < strl - 1; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            space = i;
            res = (char*)realloc(res, res_l++ * sizeof(char));
            res[sh_res] = ' ';
            sh_res++;
            if (str[i - 1 - l] == ' ') {
                sh_res = sh_res - l - 1;
                res = (char*)realloc(res, res_l += word_l - 2 * sizeof(char));
                for (int k = 0; k < word_l - 1; k++, sh_res++) {
                    if (nword[k] == '\n') {
                        res[sh_res] = ' ';
                    }
                    else {
                        res[sh_res] = nword[k];
                    }
                }
                res[sh_res] = ' ';
            }

        }
        else {
            res = (char*)realloc(res, res_l++ * sizeof(char));
            res[sh_res++] = str[i];
        }
    }
    res = (char*)realloc(res, res_l++ * sizeof(char));
    res[sh_res] = '\0';
    cout << res;

    free(nword);
    free(str);
    return 0;
}