#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

function<void()> EnterNumberInt(int& varLink, string label){
    return [&varLink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin,raw_input);
        while (!UserInputInt(raw_input))
        {
            cout << label << " = ";
            getline(cin,raw_input);
        }
        varLink = stoi(raw_input);
    };
}

void InputNatNumber(){
    int X;
    while (true) {
        cout << "Введите натуральное число X: ";
        cin >> X;

        
        if (cin.fail() || X <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите корректное натуральное число.\n";
        } else {
            return X;
        }
    }
}

bool TrueFerstAndEndNumber(int X){
    string strX = to_string(X);
    return strX.front() == strX.back();
}

bool TrueNecheEndNumber(int X){
    int lastDigit = X % 10;
    return lastDigit % 2 != 0;
}

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    std::map<int, MenuItem> menu = {
        {1, {"Task 1", InputNatNumber}},
        {2, {"Task 2", TrueFerstAndEndNumber}},
        {3, {"Task 3", TrueNecheEndNumber}}
    }
        
int choice = 0;
while (true) {
    cout << "Menu: " << endl;
    for (const auto& item : menu) {
        cout << " " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Exit" << endl;

    EnterNumberInt(choice, "Input number: ")();
    if (choice == 0) {
        cout << "© 2025 FirstName LastName" << endl;
        break;
    }
    cout << endl;

    if (menu.find(choice) != menu.end()) {
        menu[choice].action();
    }
    else {
        cout << "Oshibka." << endl;
    }

    cout << endl << endl;
    }
    return 0;
}