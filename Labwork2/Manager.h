#ifndef MANAGER_H
#define MANAGER_H


#include <list>

#include "Line.h"

using namespace std;

class Manager {
    vector<Line> Lines;
    void ManagerProgramm();
    void CreateLine();
public:
    Manager() {
        ManagerProgramm();
    }
};


#endif //MANAGER_H
