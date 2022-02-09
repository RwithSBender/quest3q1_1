#pragma once

#include "FileLoggerSingleton.h"
//#include "Bomb.h"
//#include "Plane.h"
class Bomb;
class Plane;

class Visitor
{
public:
    virtual void log(Bomb * e) = 0;
    virtual void log(Plane * e) = 0;
};

class LogVisitor : public Visitor
{
public:
    void log(Bomb* e);
    void log(Plane* e);
};