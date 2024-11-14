//
// Created by Владислав Ковригин on 07.11.2024.
//

#ifndef DATARECIPIENT_H
#define DATARECIPIENT_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DataRecipient {
    vector<string> input;
    vector<string> validInput;
    string speed;
    string length;
    string countPerSecond;
    string choice;
    bool epylepsy = false;
public:
    void GetData();
    void SetData();
};


#endif //DATARECIPIENT_H
