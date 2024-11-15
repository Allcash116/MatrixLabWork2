//
// Created by Владислав Ковригин on 11.11.2024.
//

#include "Randomizer.h"
#include "Console.h"

char Randomizer::getRandomChar() {
    random_device sd;
    mt19937 gen(sd());
    uniform_int_distribution<> distr(33, 126);
    char randomChar = distr(gen);
    return randomChar;
}

int Randomizer::getRandomColor() {
    random_device sd;
    mt19937 gen(sd());
    uniform_int_distribution<> distr(31, 37);
    int randomColor = distr(gen);
    return randomColor;
}


int Randomizer::GetRandomInt(int numberBegin, int numberEnd) {
    random_device sd;
    mt19937 gen(sd());
    uniform_int_distribution<> distr(numberBegin, numberEnd);
    int randomInt = distr(gen);
    return randomInt;
}

int Randomizer::getRandomHeight() {
    int width, height;
    Console::GetConsoleSize(width,height);
    random_device sd;
    mt19937 gen(sd());
    uniform_int_distribution<> distr(2, (height - 1));
    int randomHeight = distr(gen);
    return randomHeight;
}
