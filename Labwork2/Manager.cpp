//
// Created by Владислав Ковригин on 05.11.2024.
//

#include <iostream>

#include "Manager.h"

#include <unistd.h>

#include "Data.h"

void Manager::ManagerProgramm() {
    while(true) {
        system("clear");
        Data::OverwriteConsoleSize();
        CreateLine();
        for(int i = 0; i < Data::GetWidthConsole() + Data::GetLenght(); i++) {
            Lines.back().UpdateLine();
            Console::SetCursorPosition(1,1);
            usleep(1000 * Data::GetSpeed());
        }
    }
}

void Manager::CreateLine() {
    Lines.emplace_back();
}
