#include <iostream>

using namespace std;
// ---------------------------------------
void createPiArray (string pattern, int M, int piArray[]) {
    int len = 0;
    piArray [0] = 0;
    int i = 1;

    while ( i < M) {
        if (pattern[i] == pattern [len]) {
            len++;
            piArray[i] = len;
            i++;
        }
        else {
            if (len !=0 ) {
                len = piArray[len - 1];
            }
            else {
                piArray[i] = 0;
                i++;
            }
        }
    }//while
}

// ---------------------------------------
void KMPsearch (string text, string pattern) {
    int M = pattern.size();
    int N = text.size();
    int piArray[M];

    // ---------------------------------------
    createPiArray(pattern, M, piArray);

    std::cout << "Computed piFunction: " << endl;
    for (int i = 0; i < M; i++)
        cout << "piArray[" << i << "] = " << piArray[i] << endl;

    // ---------------------------------------
    std::cout << "\nPattern search: " << endl;
    int i = 0;
    int j = 0;

    while ((N-i) >= (M-j)) {
        if (pattern[j] = text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = piArray[j-1];
        }

        else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = piArray [j - 1];
            else
                i = i + 1;
        }
    }

}

// ---------------------------------------
int main() {
    string text  =  "AABAACAABAA";
    string pattern  = "AABA";

    std::cout << "\n\n// ---------------- KMP Algorithm Testing --------------\n";
    std::cout << "String: " << text << std::endl;
    std::cout << "String: " << pattern << std::endl;
    KMPsearch(text,pattern);

    return 0;
}
