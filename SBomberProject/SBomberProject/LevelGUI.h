#pragma once

#include <stdint.h>

#include "GameObject.h"
#include <string>
#include <vector>
#include <ctime>

using namespace std;
/*class MySoftwareBase
{
private:
    AbstractLevelGUI* levelgui;

public:
    ~MySoftwareBase() {
        delete this->levelgui;
    }
    void setStrategy(AbstractLevelGUI* new_levelgui)
    {
        delete this->levelgui;
        this->levelgui = new_levelgui;
    }
    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew) { this->SetParam(passedTimeNew, fpsNew, bombsNumberNew, scoreNew); };
    void __fastcall SetHeight(uint16_t heightN) { this->SetHeight(heightN); };
    inline uint16_t GetFinishX() { this->GetFinishX(); };
    inline void SetFinishX(uint16_t finishXN) { this->SetFinishX(finishXN); };
    void Draw() { this->Draw(); };
    inline void SetPos(double nx, double ny) { this->SetPos(nx, ny);}
    inline void SetWidth(uint16_t widthN) { this->SetWidth(widthN); }
    inline double GetY() const { this->GetY(); }
    inline double GetX() const { this->GetX(); }
};*/

class AbstractLevelGUI : public GameObject {

public:
    virtual ~AbstractLevelGUI() {};
    virtual void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew) = 0;
    virtual void __fastcall SetHeight(uint16_t heightN) = 0;
    virtual inline uint16_t GetFinishX() const = 0;
    virtual inline void SetFinishX(uint16_t finishXN) = 0;
    virtual void addMessage(string s) = 0;
};

class LevelGUI1 : public AbstractLevelGUI {
public:

    LevelGUI1() : bombsNumber(0), score(0), passedTime(0), fps(0), height(0) { }

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);

    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };

    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }
    virtual void addMessage(string s) { messages.push_back(s); }

    void Draw() const override;
    
    vector<string> messages;
    time_t lasttime;

protected:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;

};

class LevelGUI2 : public AbstractLevelGUI {
public:

    LevelGUI2() : bombsNumber(0), score(0), passedTime(0), fps(0), height(0) { }

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);

    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };

    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }
    virtual void addMessage(string s) { messages.push_back(s); }

    void Draw() const override;

    vector<string> messages;
    time_t time;

protected:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;
};



