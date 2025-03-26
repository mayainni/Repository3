#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;


bool UserInputInt(const string& input) {
    if (input.empty()) return false;

    try {
        int number = stoi(input);
        if (number <= 0) return false;
    }
    catch (const exception&) { 
        return false;
    }

    return true;
}


int InputNatNumber() {
    string raw_input;
    int X;
    
    while (true) {
        cout << "Введите натуральное число X: ";
        getline(cin, raw_input);

        if (UserInputInt(raw_input)) {
            X = stoi(raw_input);
            return X;
        }

        cout << "Ошибка! Введите корректное натуральное число.\n";
    }
}


bool TrueFirstAndEndNumber(int X) {
    string strX = to_string(X);
    return strX.front() == strX.back();
}


bool TrueNecheEndNumber(int X) {
    int lastDigit = X % 10;
    return lastDigit % 2 != 0;
}

int main() {
    int X = InputNatNumber(); 

    map<int, function<void()>> menu = {
        {1, [&]() { 
            cout << "Число начинается и заканчивается одной и той же цифрой: " 
                 << (TrueFirstAndEndNumber(X) ? "Да" : "Нет") << endl;
        }},
        {2, [&]() { 
            cout << "Число заканчивается нечетной цифрой: " 
                 << (TrueNecheEndNumber(X) ? "Да" : "Нет") << endl;
        }}
    };

    while (true) {
        cout << "\nМеню: \n";
        cout << "1. Проверить, начинается и заканчивается ли число одной и той же цифрой\n";
        cout << "2. Проверить, заканчивается ли число нечетной цифрой\n";
        cout << "0. Выход\n";
        cout << "Введите номер операции: ";

        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "© 2025 FirstName LastName\n";
            break;
        }

        if (menu.find(choice) != menu.end()) {
            menu[choice]();
        } else {
            cout << "Ошибка: неверный пункт меню.\n";
        }
    }

    return 0;
}
