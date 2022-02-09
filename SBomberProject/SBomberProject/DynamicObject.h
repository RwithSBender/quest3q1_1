#pragma once

#include <stdint.h>

#include "GameObject.h"
#include <tuple>

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
    
    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    double GetSpeed() { return speed; };
    std::tuple<double, double> GetDirection() { return { xDirction, yDirection }; };


protected:

    double speed;
    double xDirction, yDirection;

};