//
// Created by Владислав Ковригин on 05.11.2024.
//
#include "Line.h"
#include "Data.h"
#include "Randomizer.h"


void Line::CreateSymbol(int CoordinateSymbolX, int CoordinateSymbolY) {
    symbols.emplace_back(CoordinateSymbolX, CoordinateSymbolY);
    symbols.back().WriteSelf();
}

void Line::DeleteSymbol() {
    auto firstSymbolBottom = symbols.begin();
    firstSymbolBottom->EraseSelf();
    symbols.erase(firstSymbolBottom);
}

void Line::RecolourPreciousColumn() {
    if (symbols.size() > 1) {
        if (CoordinateLineX % 2 == 0) {
            auto previousSymbol = prev(symbols.end(), 3);
            previousSymbol->RecolourSymbol();
        }
        else {
            auto previousSymbolBottom = prev(symbols.end(), 3);
            previousSymbolBottom->RecolourSymbol();
            auto previousSymbolTop = prev(symbols.end(), 2);
            previousSymbolTop->RecolourSymbol();
        }
    }
}

void Line::RecolourThisColumn() {
    if (CoordinateLineX % 2 == 0) {
        auto previousSymbol = prev(symbols.end(), 1);
        previousSymbol->RecolourSymbol();
        auto previousSymbolBottom = prev(symbols.end(), 2);
        previousSymbolBottom->RecolourSymbol();
    }
    else {
        auto previousSymbolTop = prev(symbols.end(), 1);
        previousSymbolTop->RecolourSymbol();
    }
}

void Line::DrawNextColumn() {
    if (CoordinateLineX % 2 == 0) {
        CreateSymbol(CoordinateLineX, CoordinateLineY + 1);
        CreateSymbol(CoordinateLineX, CoordinateLineY - 1);
        RecolourPreciousColumn();
    }
    else {
        CreateSymbol(CoordinateLineX,CoordinateLineY);
        RecolourPreciousColumn();
    }
}

void Line::EraseLastColumn() {
    if ((CoordinateLineX - Data::GetLenght()) % 2 == 0) {
        DeleteSymbol();
        DeleteSymbol();
    }
    else {
        DeleteSymbol();
    }
}

bool Line::LineStatus() {
    if (CoordinateLineX > Data::GetWidthConsole() + Data::GetLenght()) {
        return true;
    }
    return false;
}

void Line::UpdateLine() {
    if (CoordinateLineX <= Data::GetLenght()) {
        DrawNextColumn();
        CoordinateLineX++;
    }

    else if (Data::GetLenght() < CoordinateLineX && CoordinateLineX < Data::GetWidthConsole()) {
        DrawNextColumn();
        EraseLastColumn();
        CoordinateLineX++;
    }

    else if(CoordinateLineX == Data::GetWidthConsole()) {
        DrawNextColumn();
        EraseLastColumn();
        RecolourThisColumn();
        CoordinateLineX++;
    }

    else if (CoordinateLineX > Data::GetWidthConsole()) {
        EraseLastColumn();
        CoordinateLineX++;
    }
}

