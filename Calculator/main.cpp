#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';
    bool validInput = true;

    cout << "Calculator Console Application" << endl << endl;
    cout << "Please enter the operation to perform. Format like a+b a+b+c a*c and more" << endl;
    cout << "Type 'exit' or 'quit' to exit"<< endl;

    Calculator c;
    while (true)
    {
        validInput = false;  // Assume the input is not valid by default

        string input;
        if (cin >> input)
        {
            if (input == "exit" || input == "quit") {
                break; // Exit the loop if "exit" or "quit" is entered
            }

            size_t pos = 0;
            string delimiter = "+-*/";
            while ((pos = input.find_first_of(delimiter)) != string::npos) {
                string token = input.substr(0, pos);
                if (sscanf(token.c_str(), "%lf", &x) == 1) {
                    if (validInput) {
                        result = c.Calculate(result, oper, x);
                    } else {
                        result = x;
                        validInput = true;
                    }
                } else {
                    cout << "Invalid input format. Please try again." << endl;
                    break;
                }
                oper = input[pos];
                input.erase(0, pos + 1);
            }

            if (!input.empty()) {
                if (sscanf(input.c_str(), "%lf", &x) == 1) {
                    if (validInput) {
                        result = c.Calculate(result, oper, x);
                    } else {
                        cout << "Invalid input format. Please enter an operator and a second value." << endl;
                    }
                } else {
                    cout << "Invalid input format. Please try again." << endl;
                }
            }

            if (validInput) {
                cout << "Result is: " << result << endl;
            }
        }
        else
        {
            cout << "Invalid input format. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
