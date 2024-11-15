//
// Created by Владислав Ковригин on 07.11.2024.
//

#include "Data.h"
#include "Randomizer.h"

int Data::SPEED = 0;
int Data::LENGHT = 0;
int Data::COUNT_PER_SECOND = 0;
int Data::WIDTH_CONSOLE = 1;
int Data::HEIGHT_CONSOLE = 1;
bool Data::EPYLEPSY = false;
vector<int> Data::POINTS_IN_TIME;

vector<int> Data::GetPointsInTime() {
    int sleepMS = 0;
    int speedCounter = 0;
    for(int i = 0; i < 1000 / SPEED; i++) {
        speedCounter += SPEED;
        POINTS_IN_TIME.push_back(speedCounter);
    }
    for (int i = 0; i <= 1000 / COUNT_PER_SECOND - 1; i++) {
        sleepMS = Randomizer::GetRandomInt(COUNT_PER_SECOND * i, COUNT_PER_SECOND * (i + 1));
        if (find(POINTS_IN_TIME.begin(), POINTS_IN_TIME.end(), sleepMS) != POINTS_IN_TIME.end()) {
            sleepMS++;
            POINTS_IN_TIME.push_back(sleepMS);
        }
        else {
            POINTS_IN_TIME.push_back(sleepMS);
        }
    }
    sort(POINTS_IN_TIME.begin(), POINTS_IN_TIME.end());
    return POINTS_IN_TIME;
}
void Data::ClearPointsInTime() {
    POINTS_IN_TIME.clear();
}
