//
// Created by Владислав Ковригин on 05.11.2024.
//

#ifndef LINE_H
#define LINE_H
#include <list>

#include "Symbol.h"

using namespace std;

class Line {
    list<Symbol> symbols;
    int CoordinateLineX, CoordinateLineY;

    void CreateSymbol(int CoordinateSymbolX, int CoordinateSymbolY);
    void DeleteSymbol();

    void RecolourPreciousColumn();
    void RecolourThisColumn();

    void DrawNextColumn();
    void EraseLastColumn();

public:
    void UpdateLine();
    Line(){
        CoordinateLineX = 1;
        CoordinateLineY = Randomizer::getRandomHeight();
    }
    ~Line() {
        symbols.clear();
    }
};



#endif //LINE_H
