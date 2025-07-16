#include <iostream>
using namespace std;


void countdown(int n){
    if(n == 0){
        cout << "Happiest Birthday!" << endl;
        return;
    }
    cout << n << " days until your birthday!" << endl;
    countdown(n - 1);
    
}

int main(){
    int n;
    cout << "Enter the number of days until your birthday: ";
    cin >> n;

    if(n == 0){
        cout << "Happiest Birthday!" << endl;
    }else{
        countdown(n);
    }
    return 0;
}