#include <iostream>
using namespace std;

int countVowels(string str, int index) {
    if (index == str.length()) {
        return 0;
    }
    
    char currentChar = tolower(str[index]);
    int count = (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
                 currentChar == 'o' || currentChar == 'u') ? 1 : 0;

    return count + countVowels(str, index + 1);
}

int main() {
    string str = "Hello World";
    int vowelCount = countVowels(str, 0);
    cout << "Number of vowels in \"" << str << "\": " << vowelCount << endl;
    return 0;
}