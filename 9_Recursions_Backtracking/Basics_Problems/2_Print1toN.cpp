#include <iostream>
using namespace std;

void updator(int n){
    if(n == 0){
        return;
    }
    updator(n - 1);
    cout << n << " ";
}

int main(){
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if(n < 1){
        cout << "Please enter a number greater than 0." << endl;
    }
    else{
        cout << "Numbers from 1 to " << n << ": ";
        updator(n);
        cout << endl;
    }
    return 0;
}