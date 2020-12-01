#cmake_minimum_required(VERSION 3.16)
project(Boom)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE PATH "" FORCE)

set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_C_FLAGS ${MTM_FLAGS_DEBUG})


add_executable(CourseManager
        main1.cpp
        CoursesManager.cpp
        AVLTree.cpp
        AVLNode.cpp
        Node.cpp
        List.cpp
        Auxiliaries.cpp
        BoomExceptions.cpp
        library.cpp
        CourseNode.cpp CourseNode.h)

add_executable(AVL
        AVL_main.cpp
        AVLTree.cpp
        AVLNode.cpp
        Auxiliaries.cpp
        BoomExceptions.cpp
        )