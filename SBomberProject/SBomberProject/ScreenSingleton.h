#pragma once

#include <stdint.h>
#include "MyTools.h"

class ScreenSingleton
{
public:

    static ScreenSingleton& getInstance()
    {
        static ScreenSingleton theInstance;
        return theInstance;
    }

    void ClrScr();
    void __fastcall GotoXY(double x, double y);
    uint16_t GetMaxX();
    uint16_t GetMaxY();
    void SetColor(ConsoleColor color);

private:
    ScreenSingleton() { }
    ScreenSingleton(const ScreenSingleton& root) = delete;
    ScreenSingleton& operator=(const ScreenSingleton&) = delete;
};
