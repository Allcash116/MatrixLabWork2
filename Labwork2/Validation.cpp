//
// Created by Владислав Ковригин on 07.11.2024.
//



#include "Validation.h"

#include "Data.h"


void Validation::ValidParametrs(int argc, char* argv[]) {
    if (argc == 2) {
        system("clear");
        cout << "Информация о программе:" << "\n";
        cout << "1 параметр - Скорость (1 - 30)" << "\n";
        cout << "2 параметр - Длина (1 - 30)" << "\n";
        cout << "3 параметр - Количество линий в секунду (1 - 30)" << "\n";
        cout << "4 параметр - режим эпилепсии (y/n)" << "\n";
        cout << "Пожалуйста введите данные через пробел" << "\n";
        getline(cin, input);
        istringstream stream1(input);
        while (stream1 >> token) {
            tokens.push_back(token);
        }
        if (tokens.size() != 4) {
            while (tokens.size() != 4) {
                tokens.clear();
                cout << "Неверное количество данных пожалуйста введите данные через пробел" << "\n";
                getline(cin, input);
                istringstream stream2(input);
                while (stream2 >> token) {
                    tokens.push_back(token);
                }
            }
        }
        tokens = ValidInput(tokens);
        if (tokens[3] == "y" || tokens[3] == "Y") {
            epylepsy = true;
        }
        else {
            epylepsy = false;
        }
        Data::SetValues(stoi(tokens[0]),stoi(tokens[1]),stoi(tokens[2]),epylepsy);
    }
    else if(argc == 5) {
        tokens.clear();

        for (int i = 1; i < argc; ++i) {
            tokens.emplace_back(argv[i]);
        }
        ValidInput(tokens);
        if (tokens[3] == "y") {
            epylepsy = true;
        }
        else {
            epylepsy = false;
        }
        Data::SetValues(stoi(tokens[0]),stoi(tokens[1]),stoi(tokens[2]),epylepsy);
    }
    else if(argc == 1){
        data.GetData();
        data.SetData();
    }
    else {
        while (tokens.size() != 4) {
            tokens.clear();
            cout << "Неверное количество данных пожалуйста введите данные через пробел" << "\n";
            getline(cin, input);
            istringstream stream2(input);
            while (stream2 >> token) {
                tokens.push_back(token);
            }
        }
        if (tokens[3] == "y" || tokens[3] == "Y") {
            epylepsy = true;
        }
        else {
            epylepsy = false;
        }
        Data::SetValues(stoi(tokens[0]),stoi(tokens[1]),stoi(tokens[2]),epylepsy);
    }
}

vector<string> Validation::ValidInput(vector<string> tokens) {

    while (!isInteger(tokens[0])) {
        cout << "Неверное значение скорости, введите верное(1-30): ";
        cin.clear();
        cin.sync();
        getline(cin,tokens[0]);
    }
    while(stoi(tokens[0]) > 30 || stoi(tokens[0]) < 1) {
        cout << "Неверное значение скорости, введите верное(1-30): ";
        getline(cin, tokens[0]);
        while (!isInteger(tokens[0])) {
            cout << "Неверное значение скорости, введите верное(1-30): ";
            getline(cin,tokens[0]);
        }
    }

    while (!isInteger(tokens[1])) {
        cout << "Неверное значение длины, введите верное(1-30): ";
        getline(cin,tokens[1]);
    }
    while(stoi(tokens[1]) > 30 || stoi(tokens[1]) < 1) {
        cout << "Неверное значение длины, введите верное(1-30): ";
        getline(cin,tokens[1]);
        while (!isInteger(tokens[1])) {
            cout << "Неверное значение длины, введите верное(1-30): ";
            getline(cin,tokens[1]);
        }
    }

    while (!isInteger(tokens[2])) {
        cout << "Неверное значение, введите верное(1-30): ";
        getline(cin, tokens[2]);
    }
    while (stoi(tokens[2]) > 30 || stoi(tokens[2]) < 0) {
        cout << "Неверное значение, введите верное(1-30): ";
        getline(cin, tokens[2]);
        while (!isInteger(tokens[2])) {
            cout << "Неверное значение, введите верное(1-30): ";
            getline(cin, tokens[2]);
        }
    }

    while (isInteger(tokens[3])) {
        cout << "вы ввели число, введите Y или N ";
        getline(cin, tokens[3]);
    }
    while (!isChoise(tokens[3])) {
        cout << "вы ввели неверное значение, введите Y или N ";
        getline(cin, tokens[3]);
    }

    return tokens;
}

string Validation::trimLeadingSpaces(const string &str) {
    size_t start = str.find_first_not_of(' ');
    return (start == std::string::npos) ? "" : str.substr(start);
}

bool Validation::isInteger(const string& str) {
    trimLeadingSpaces(str);
    try {
        size_t pos;
        stoi(str, &pos);
        return pos == str.size();  // Проверяем, что вся строка была числом
    } catch (...) {
        return false;
    }
}

bool Validation::isChoise(const string& str) {
    if (str.size() != 1) {
        return false;
    }

    char firstChar = tolower(str[0]);
    return firstChar == 'y' || firstChar == 'n';
}

