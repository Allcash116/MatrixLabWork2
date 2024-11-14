#include "DataRecipient.h"

#include <cstdlib>
#include <iostream>

#include "Data.h"
#include "Validation.h"

using namespace std;

void DataRecipient::GetData() {
    system("clear");

    cout << "Скорость(значения 1-30): ";
    getline(cin,speed);
    input.push_back(speed);


    cout << "Длина(значения 1-30): ";
    getline(cin,length);
    input.push_back(length);

    cout << "Количество линий в секунду(значения 1-30): ";
    getline(cin, countPerSecond);
    input.push_back(countPerSecond);

    cout << "Режим эпилепсии ";
    cout << "Введите знак (Y/N): ";
    getline(cin, choice);
    input.push_back(choice);


    Validation validation;
    validInput = validation.ValidInput(input);

    if (validInput[3] == "y" || validInput[3] == "Y") {
        epylepsy = true;
    }
    else {
        epylepsy = false;
    }
}

void DataRecipient::SetData() {
    Data::SetValues(stoi(validInput[0]),stoi(validInput[1]),stoi(validInput[2]),epylepsy);
}

