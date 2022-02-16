#include <iostream>

#include "LevelGUI.h"
#include "MyTools.h"
#include "ScreenSingleton.h"
#include "Tank.h"
#include <vector>
#include <string>
#include <time.h>

using namespace std;


/*class Mediator {
public:

    void AddMessage(Tank* pNewTank) { v.push_back(pNewTank); };

    void Notify(Tank* from, string info) {
        for (Tank* pElem : v)
        {
            if (pElem != from)
                pElem->BeNotified(info);
        }
    }

private:
    vector<Tank*> v;
};*/


void LevelGUI1::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_White);

    ScreenSingleton::getInstance().GotoXY(x, y);
    char* buf = new (nothrow) char[width + 1];
    if (buf == nullptr)
    {
        return;
    }
    memset(buf, '+', width);
    buf[width] = '\0';
    cout << buf;
    ScreenSingleton::getInstance().GotoXY(x, y + height);
    cout << buf;
    delete [] buf;
    buf = nullptr;
    
    for (size_t i = size_t(y); i < height + y; i++)
    {
        ScreenSingleton::getInstance().GotoXY(x, (double)i);
        cout << "+";
        ScreenSingleton::getInstance().GotoXY(x + width - 1, (double)i);
        cout << "+";
    }

    ScreenSingleton::getInstance().GotoXY(3, 1);
    cout << "FramePerSecond: " << static_cast<int>(fps / (passedTime / 1000.0));
    ScreenSingleton::getInstance().GotoXY(25, 1);
    cout << "PassedTime: " << static_cast<int>(passedTime / 1000.0) << " sec";
    ScreenSingleton::getInstance().GotoXY(46, 1);
    cout << "BombsNum: " << bombsNumber;
    ScreenSingleton::getInstance().GotoXY(62, 1);
    cout << "Score: " << score;
    
}

void __fastcall LevelGUI1::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
}

void LevelGUI2::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_Green);//(CC_White);

    ScreenSingleton::getInstance().GotoXY(x, y);
    char* buf = new (nothrow) char[width + 1];
    if (buf == nullptr)
    {
        return;
    }
    memset(buf, '+', width);
    buf[width] = '\0';
    cout << buf;
    ScreenSingleton::getInstance().GotoXY(x, y + height);
    cout << buf;
    delete[] buf;
    buf = nullptr;

    for (size_t i = size_t(y); i < height + y; i++)
    {
        ScreenSingleton::getInstance().GotoXY(x, (double)i);
        cout << "+";
        ScreenSingleton::getInstance().GotoXY(x + width - 1, (double)i);
        cout << "+";
    }

    ScreenSingleton::getInstance().GotoXY(3, 1);
    cout << "FramePerSecond: " << static_cast<int>(fps / (passedTime / 1000.0));
    ScreenSingleton::getInstance().GotoXY(25, 1);
    cout << "PassedTime: " << static_cast<int>(passedTime / 1000.0) << " sec";
    ScreenSingleton::getInstance().GotoXY(46, 1);
    cout << "BombsNum: " << bombsNumber;
    ScreenSingleton::getInstance().GotoXY(62, 1);
    cout << "Score: " << score;
}

void __fastcall LevelGUI2::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
}
