#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool is_number_string(const string& s){
    int len = s.length();
    for (int i = 0; i < len; i++){
        if (s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    return true;
}

int main(){
    string cc_number;

    cout << "Welcome to credit card validator!\n";
    cout << "Enter 'exit' to quit the program\n";

    while (true){
        cout << "Please enter a credit card number to validate\n";
        cin >> cc_number;

        if (cc_number == "exit"){
            break;
        }

        else if (!is_number_string(cc_number)){
            cout << "Check the input and try again.";
            continue;
        }

        int len = cc_number.length();
        int double_even_sum = 0;

        for (int i = len - 2; i >= 0; i = i - 2){
            int dbl = ((cc_number[i] - 48) * 2);
            if (dbl > 9){
                dbl = (dbl / 10) + (dbl % 10);
            }
            double_even_sum += dbl;
        }

        for (int i = len - i; i >= 0; i = i - 2){
            double_even_sum += (cc_number[i] - 48);
        }

        cout << (double_even_sum % 10 == 0 ? "Valid number!" : "Invalid number.") << endl;

        continue;
    }
    return 0;
}