cmake_minimum_required(VERSION 2.8.12.2)
project(mtm_ex2)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtm_ex2  Skill.cpp Skill.h Citizen.cpp Citizen.h Employee.cpp Employee.h
        Manager.h Manager.cpp local/cityTestsBiadsy.cpp Workplace.cpp Workplace.h Faculty.h City.cpp City.h)
                                                                            #dry.cpp main.cpp cityTestsBiadsy.cpp

