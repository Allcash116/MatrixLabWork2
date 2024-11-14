//
// Created by Владислав Ковригин on 07.11.2024.
//

#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "DataRecipient.h"

using namespace std;


class Validation {
    bool epylepsy = false;
    DataRecipient data;
    string input;
    string token;
    vector<string> tokens;
public:
    void ValidParametrs(int argc, char* argv[]);
    vector<string> ValidInput(vector<string> tokens);
private:
    string trimLeadingSpaces(const string& str);
    bool isInteger(const string& str);
    bool isChoise(const string& str);
};



#endif //VALIDATION_H
