//
// Created by Владислав Ковригин on 07.11.2024.
//

#ifndef DATA_H
#define DATA_H
#include <vector>

#include "Console.h"

using namespace std;

class Data {
    static int SPEED;
    static int LENGHT;
    static int COUNT_PER_SECOND;
    static bool EPYLEPSY;
    static int WIDTH_CONSOLE;
    static int HEIGHT_CONSOLE;
    static vector<int> POINTS_IN_TIME;
public:
    static void SetValues(int speed, int lenght, int count_per_second, bool epylepsy) {
        SPEED = 1000 / speed;
        LENGHT = lenght;
        COUNT_PER_SECOND = 1000 / count_per_second;
        EPYLEPSY = epylepsy;
        Console::GetConsoleSize(WIDTH_CONSOLE,HEIGHT_CONSOLE);

    };

    static void OverwriteConsoleSize() {
        Console::GetConsoleSize(WIDTH_CONSOLE,HEIGHT_CONSOLE);
    }

    static vector<int> GetPointsInTime();

    static void ClearPointsInTime();

    static int GetSpeed() {
        return SPEED;
    }
    static int GetLenght() {
        return  LENGHT;
    }
    static int GetCountPerSecond() {
        return  COUNT_PER_SECOND;
    }
    static bool GetEpylepsy() {
        return EPYLEPSY;
    }
    static int GetWidthConsole() {
        return WIDTH_CONSOLE;
    }
    static int GetHeightConsole() {
        return HEIGHT_CONSOLE;
    }
};



#endif //DATA_H
