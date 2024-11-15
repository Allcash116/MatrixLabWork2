//
// Created by Владислав Ковригин on 05.11.2024.
//

#include <iostream>
#include "Manager.h"
#include "Data.h"
#include <chrono>
#include <thread>



void Manager::ManagerProgramm() {
    system("clear");
    int quantOfTime = 0;
    while(true) {
        quantOfTime = 0;
        Data::OverwriteConsoleSize();

        Data::ClearPointsInTime();
        POINTS_IN_TIME = Data::GetPointsInTime();


        size_t current_index = 0;

        while (current_index < POINTS_IN_TIME.size()) {
            if (quantOfTime == POINTS_IN_TIME[current_index]) {
                if (POINTS_IN_TIME[current_index] % Data::GetSpeed() == 0) {
                    if (Lines.size() == 0) {
                        current_index++;
                        quantOfTime++;
                        this_thread::sleep_for(chrono::milliseconds(1));
                        continue;
                    }
                    for (auto object = Lines.begin(); object != Lines.end(); ++object) {
                        object->UpdateLine();
                        if(object->LineStatus()) {
                            Lines.erase(object);
                        }
                        Console::SetCursorPosition(1,1);
                    }
                }
                else {
                    CreateLine();
                    Lines.back().UpdateLine();
                }
                current_index++;
            }
            quantOfTime++;
            this_thread::sleep_for(chrono::milliseconds(1));
        }
    }
}

void Manager::CreateLine() {
    Lines.emplace_back();
}
