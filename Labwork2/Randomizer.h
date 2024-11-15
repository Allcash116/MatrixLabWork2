//
// Created by Владислав Ковригин on 11.11.2024.
//

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

using namespace std;

class Randomizer {
public:
    static char getRandomChar();
    static int getRandomColor();

    static int GetRandomInt(int numberBegin,int numberEnd);

    static int getRandomHeight();
};



#endif //RANDOMIZER_H
