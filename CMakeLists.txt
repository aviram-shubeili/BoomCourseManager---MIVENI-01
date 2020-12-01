#cmake_minimum_required(VERSION 3.16)
project(Boom)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE PATH "" FORCE)

set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_C_FLAGS ${MTM_FLAGS_DEBUG})


add_executable(Boom
        AVL_main.cpp
        CoursesManager.cpp
        AVLTree.cpp
        AVLNode.cpp
        #Course.cpp
       # Node.cpp
      #  List.cpp
        Auxiliaries.cpp
        )