#include <iostream>
using namespace std;

void toUpperCase(string &str, int index) {
    if (index == str.length()) {
        return;
    }
    str[index] = toupper(str[index]);
    toUpperCase(str, index + 1);
}

void toLowerCase(string &str, int index) {
    if (index == str.length()) {
        return;
    }
    str[index] = tolower(str[index]);
    toLowerCase(str, index + 1);
}

int main() {
    string str = "hello world";
    toUpperCase(str, 0);
    cout << "Uppercase String: " << str << endl;
    toLowerCase(str, 0);
    cout << "Lowercase String: " << str << endl;
    return 0;
}
