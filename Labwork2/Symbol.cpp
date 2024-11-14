//
// Created by Владислав Ковригин on 10.11.2024.
//

#include "Symbol.h"

#include "Console.h"
#include "Data.h"

void Symbol::WriteSelf() {
    Console::SetCursorPosition(coordinateSymbolX, coordinateSymbolY);
    Console::SetTextColor(37);
    cout << symbol;
}

void Symbol::EraseSelf() {
    Console::SetCursorPosition(coordinateSymbolX, coordinateSymbolY);
    cout << " ";
}

void Symbol::RecolourSymbol() {
    if(Data::GetEpylepsy()) {
        Console::SetTextColor(Randomizer::getRandomColor());
        EraseSelf();
        Console::SetCursorPosition(coordinateSymbolX,coordinateSymbolY);
        cout << symbol;
    }
    else {
        Console::SetTextColor(32);
        EraseSelf();
        Console::SetCursorPosition(coordinateSymbolX,coordinateSymbolY);
        cout << symbol;
    }
}

int Symbol::GetX() {
    return coordinateSymbolX;
}

int Symbol::GetY() {
    return coordinateSymbolY;
}
