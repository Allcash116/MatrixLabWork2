//
// Created by Владислав Ковригин on 05.11.2024.
//

#include <iostream>

#include "Manager.h"

#include <unistd.h>

#include "Data.h"

void Manager::ManagerProgramm() {
    system("clear");
    while(true) {
        Data::OverwriteConsoleSize();
        if(Lines.size() < 2) {
            usleep(1000 * Data::GetSpeed());
            CreateLine();
        }
        for (auto object = Lines.begin(); object != Lines.end(); ++object) {
            object->UpdateLine();
            if(object->LineStatus()) {
                Lines.erase(object);
            }
        }
        Console::SetCursorPosition(1,1);
        usleep(1000 * Data::GetSpeed());
    }
}

void Manager::CreateLine() {
    Lines.emplace_back();
}
