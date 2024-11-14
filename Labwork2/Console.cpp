#include "Console.h"


#include <iostream>

using namespace std;

void Console::SetCursorPosition(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
    cout.flush();
}
void Console::SetTextColor(int Color) {
    cout << "\033[0" << ";" << Color << "m";
}

void Console::GetConsoleSize(int &width, int &height) {
    FILE* fp = popen("stty size", "r");
    if (fp == nullptr) {
        std::cerr << "Ошибка при получении размера консоли." << std::endl;
        return;
    }
    fscanf(fp, "%d %d", &height, &width);
    pclose(fp);
}


