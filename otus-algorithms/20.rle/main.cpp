#include <iostream>
#include <string>
using namespace std;


// ---------------------------------------
string RLEcoding (string str) {
    int n = str.length();
    string str_encoded;


    for (int i = 0; i < n; i++) {
        int count = 1;

        while (str [i] == str [i+1]) {
            count ++;
            i++;
        }
        str_encoded += to_string(count) + str[i];
    }

    return str_encoded;
};

// ---------------------------------------
int main() {

    string str = "tttaaaderrrrrrymmmm";

    cout << "String         : " << str << " (" << str.length() << " bytes)" << endl;
    cout << "String encoded : " << RLEcoding(str) << " (" << RLEcoding(str).length() << " bytes)" <<endl;;

    return 0;
}
