#include <bits/stdc++.h>
using namespace std;
const int m = 50;

class item{
    int itemCode[m];
    float itemPrice[m];
    int count;

public:
    void cnt(){
        count = 0;
    }
    void getdata(void);
    void display(void);
    void remove(void);
    void displayItem(void);
};

void item::getdata(void){
    cout << "Enter the item code: ";
    cin >> itemCode[count];
    cout << "Enter the item price: ";
    cin >> itemPrice[count];
    count++;
}

void item::display(void){
    cout << "Item Code\tItem Price\n";
    for (int i = 0; i < count; i++)
    {
        cout << itemCode[i] << "\t\t" << itemPrice[i] << endl;
    }
}

void item::remove(void){
    int code;
    cout << "Enter the item code to remove: ";
    cin >> code;
    for (int i = 0; i < count; i++){
        if (itemCode[i] == code){
            itemPrice[i] = 0;
        }
    }
}

void item::displayItem(void){
    cout << "Item Code\tItem Price\n";
    for (int i = 0; i < count; i++){
        if (itemPrice[i] != 0){
            cout << itemCode[i] << "\t\t" << itemPrice[i] << endl;
        }
    }
}

int main(){
    item obj;
    obj.cnt();
    int choice;
    do{
        cout << "1. Add Item\n2. Display All Items\n3. Remove Item\n4. Display Available Items\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.getdata();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.remove();
            break;
        case 4:
            obj.displayItem();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


/*
    Conclusion:
    1. Classes are user-defined data types that represent real-world entities.
    2. They encapsulate data and functions that operate on that data.
    3. Objects are instances of classes.
    4. Constructors and destructors are special member functions for initialization and cleanup.
    5. Access specifiers (public, private, protected) control access to class members.
    6. Static members are shared among all instances of a class.
    7. Member functions can be defined inside or outside the class definition by using the scope resolution operator (::).
*/