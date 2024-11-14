//
// Created by Владислав Ковригин on 10.11.2024.
//

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

#include "Randomizer.h"


class Symbol {
    int coordinateSymbolX = 0;
    int coordinateSymbolY = 0;
    char symbol = ' ';
public:
    Symbol(int x, int y) {
        coordinateSymbolX = x;
        coordinateSymbolY = y;
        symbol = Randomizer::getRandomChar();
    }
    void WriteSelf();
    void EraseSelf();
    void RecolourSymbol();
    int GetX();
    int GetY();
};



#endif //SYMBOL_H
