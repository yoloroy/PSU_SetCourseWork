cmake_minimum_required(VERSION 3.28)
project(SetCourseWork)

set(CMAKE_CXX_FLAGS_DEBUG "-D_DEBUG -O0 -g")
set(CMAKE_CXX_STANDARD 20)

add_executable(SetCourseWork main.cpp
        Set.h
        std_implementations/SetUsingStdForwardList.cpp
        std_implementations/SetUsingStdForwardList.h
        MeasureTime.h
        std_implementations/SetUsingStdUnorderedMultimap.cpp
        std_implementations/SetUsingStdUnorderedMultimap.h
        std_implementations/SetUsingStdList.cpp
        std_implementations/SetUsingStdList.h
        std_implementations/SetUsingStdSet.cpp
        std_implementations/SetUsingStdSet.h
        SetUsingSinglyLinkedList.cpp
        SetUsingSinglyLinkedList.h
        TestSet.h
        util/centered.h)
