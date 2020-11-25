//
// Created by avira on 23/11/2020.
//

#ifndef BOOM_BOOMEXCEPTIONS_H
#define BOOM_BOOMEXCEPTIONS_H
#include <exception>

class BoomExceptions : public std::exception{ };

class InvalidInput : public BoomExceptions{ };


#endif //BOOM_BOOMEXCEPTIONS_H
