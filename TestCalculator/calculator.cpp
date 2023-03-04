#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
//test

enum choice {addi=1, subtr=2, multipl=3, divi=4, pullOut=5};
map<string, choice> choices;

void register_choices()
{
    choices["addition"] = addi;
    choices["subtraction"] = subtr;
    choices["multiplication"] = multipl;
    choices["division"] = divi;
    choices["exit"] = pullOut;
}

void calculations(int arg)
{
    int a, b, result;
    switch (arg)
    {
        case addi:
            cout << "\tEnter first addend\n";
            cin >> a;
            cout << "\tEnter second addend\n";
            cin >> b;
            result = a + b;
            cout << "\tSum: " << result << endl;
            break;
        case subtr:
            cout << "\tEnter minuend\n";
            cin >> a;
            cout << "\tEnter subtrahend\n";
            cin >> b;
            result = a - b;
            cout << "\tDifference: " << result << endl;
            break;
        case multipl:
            cout << "\tEnter multiplicand\n";
            cin >> a;
            cout << "\tEnter multiplicator\n";
            cin >> b;
            result = a * b;
            cout << "\tProduct: " << result << endl;
            break;
        case divi:
            cout << "\tEnter dividend\n";
            cin >> a;
            cout << "\tEnter divisor\n";
            cin >> b;
            result = a / b;
            cout << "\tQuotient: " << result << endl;
            break;
        default:
            cout << "\tERROR: Something went wrong...\n";
            break;
    }
}

int main()
{
    register_choices();
    string input;
    bool c = true;

    while(c)
    {
        cout << "Please enter what operation you want to perform (or 'exit' to quit)\n\n";
        cin >> input;

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        switch (choices[input])
        {
            case addi:
                cout << "\nAddition Selected: \n"; 
                calculations(addi);
                break;
            case subtr:
                cout << "\nSubtraction Selected: \n"; 
                calculations(subtr);
                break;
            case multipl:
                cout << "\nMultiplication Selected: \n"; 
                calculations(multipl);
                break;
            case divi:
                cout << "\nDivision Selected: \n"; 
                calculations(divi);
                break;
            case pullOut:
                cout << "\nExiting...\n"; 
                c = !c;
                break;
            default:
                cout << "\nERROR: Invalid entry. Please input an acceptable operation.\n";
        }
    }

    return 0;
}