#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "Command.h"
#include "Visitor.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    AbstractLevelGUI * FindLevelGUI() const;
    Invoker invoker;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    LogVisitor logVis;

    void SetGui(AbstractLevelGUI* newgui);
    class BombIterator
    {
        vector<DynamicObject*> vecBombs;
        int curIndex;
        Bomb* ptr;
    public:
        BombIterator(vector<DynamicObject* > ref) : vecBombs(ref), curIndex(-1), ptr(nullptr) { ++(*this); }
        void reset() { curIndex = -1; ptr = nullptr; }

        BombIterator& operator++ () // префиксный инкремент
        {
            curIndex++;
            if (curIndex == -1)
                curIndex = 0;
            for (; curIndex < vecBombs.size(); curIndex++)
            {
                Bomb* pBomb = dynamic_cast<Bomb*>(vecBombs[curIndex]);
                if (pBomb != nullptr)
                {
                    ptr = pBomb;
                    break;
                }
            }
            if (curIndex == vecBombs.size())
            {
                curIndex = -1;
                ptr = nullptr;
            }
            return *this;
        }
        BombIterator& operator-- () // префексный декремент
        {
            if (curIndex == -1)
                curIndex = vecBombs.size() - 1;

            for (; curIndex >= 0; curIndex--)
            {
                /*if (vecBombs[curIndex] % 2 == 0)
                {
                    ptr = &vecBombs[curIndex];
                    break;
                }*/
            }
            if (curIndex == -1)
            {
                ptr = nullptr;
            }
            return *this;
        }
        DynamicObject* operator*() // операция разыменования итератора
        {
            return vecBombs.at(curIndex);
        }
        bool operator==(BombIterator it) // проверка на лог. равенство итераторов
        {
            if (curIndex == it.curIndex &&
                ptr == it.ptr &&
                vecBombs == it.vecBombs)
            {
                return true;
            }
            return false;
        }
        bool operator!=(BombIterator it) // проверка на лог. неравенство
        {
            return !(*this == it);
        }
    };
        // получаем итератор настроенный на начало массива
    BombIterator begin(vector<DynamicObject*> vecDynamicOb) { BombIterator it(vecDynamicOb); return it; }
        // итератор в конечном состоянии
    BombIterator end(vector<DynamicObject*> vecDynamicOb) { BombIterator it(vecDynamicOb); it.reset(); return it; }
};