cmake_minimum_required(VERSION 3.16)
project(LM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LM
        Azmoon.cpp
        Azmoon.h
        Daneshjoo.h
        Dars.cpp
        Dars.h
        Handler.h
        Karbar.h
        LogIn.h
        main.cpp
        Ostad.h
        Soual.cpp
        Soual.h)
