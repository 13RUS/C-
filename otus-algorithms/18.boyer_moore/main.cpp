#include <iostream>

using namespace std;
# define NO_OF_CHARS 128

 void createOffsetTable (string pattern, int offset[NO_OF_CHARS]) {

    for (int i = 0; i < NO_OF_CHARS; i++)
        offset [i] = -1;

    for (int i = 0; i < pattern.size(); i++) {
        offset [(int)pattern[i]] = i;
    }
}

// ---------------------------------------
void offsettable_search (string text, string pattern) {

    int M = pattern.size();
    int N = text.size();
    int offset [NO_OF_CHARS];

    createOffsetTable (pattern, offset);

    int t = 0;

    while (t <= N - M) {
        int p = M - 1;

        while (p >= 0 && text[t + p] == pattern [p]) {
            p--;
        }

        if (p < 0) {
            cout << "Pattern found at index " << t << endl;
            t += (t + M < N) ? M-offset[text[t + M]] : 1;
        }
        else
            t += max (1, p - offset [text[t + p]]);

    }
 }

// ---------------------------------------
void bruteforce_search (string text, string pattern){
    int M = pattern.size();
    int N = text.size();

    for (int i = 0; i <= N-M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (text[i + j] != pattern[j]) break;

        if (j == M) cout << "Pattern found at index " << i << endl;
    }

}

// ---------------------------------------
int main() {

     string text  =  "AAKOLOLOKOLOKOL";
     string pattern  = "KOLOKOL";
     bruteforce_search( text, pattern);

     text= "ABAAABCD";
     pattern = "ABC";
     offsettable_search(text, pattern);

     text = "AAKOLOLOKOLOKOL";
     pattern = "KOLOKOL";
     offsettable_search(text, pattern);

     return 0;
}
