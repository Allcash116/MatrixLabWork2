cmake_minimum_required(VERSION 3.28)
project(Labwork2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Labwork2 main.cpp
        Manager.cpp
        Manager.h
        Line.cpp
        Line.h
        Console.cpp
        Console.h
        DataRecipient.cpp
        DataRecipient.h
        Validation.cpp
        Validation.h
        Data.cpp
        Data.h
        Symbol.cpp
        Symbol.h
        Randomizer.cpp
        Randomizer.h)
