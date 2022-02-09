
#include "Visitor.h"
#include "Bomb.h"
#include "Plane.h"




    void LogVisitor::log(Bomb* e)
    {
        double speed = e->GetSpeed();
        auto [xdir, ydir] = e->GetDirection();
        FileLoggerSingleton::getInstance().WriteToLog("BOMB Speed=" + to_string(speed) + " Xdir=" + to_string(xdir) + " Ydir=" + to_string(ydir));
    }
    void LogVisitor::log(Plane* e)
    {
        double speed = e->GetSpeed();
        auto [xdir, ydir] = e->GetDirection();
        FileLoggerSingleton::getInstance().WriteToLog("Plane Speed=" + to_string(speed) + " Xdir=" + to_string(xdir) + " Ydir=" + to_string(ydir));
    }