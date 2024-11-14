//
// Created by Владислав Ковригин on 06.11.2024.
//

#ifndef CONSOLE_H
#define CONSOLE_H



class Console {
public:
    static void SetCursorPosition(int x, int y);
    static void SetTextColor(int Color);
    static void GetConsoleSize(int &width, int &height);
};

#endif //CONSOLE_H
