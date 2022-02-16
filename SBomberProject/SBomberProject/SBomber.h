#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomberImpl
{
public:

    SBomberImpl();
    ~SBomberImpl();

    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    //

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject* pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

class SBomber
{
public:

    SBomber() { m_sbomb = new SBomberImpl; };
    ~SBomber() { delete m_sbomb; };
    
    inline bool GetExitFlag() const { return m_sbomb->GetExitFlag(); }

    void ProcessKBHit() { m_sbomb->ProcessKBHit(); };
    void TimeStart() { m_sbomb->TimeStart(); };
    void TimeFinish() { m_sbomb->TimeFinish(); };

    void DrawFrame() { m_sbomb->DrawFrame(); };
    void MoveObjects() { m_sbomb->MoveObjects(); };
    void CheckObjects();

private:
    SBomberImpl* m_sbomb;
    void CheckPlaneAndLevelGUI() { m_sbomb->CheckPlaneAndLevelGUI(); }
    void CheckBombsAndGround() { m_sbomb->CheckBombsAndGround(); }
    void __fastcall CheckDestoyableObjects(Bomb* pBomb) { m_sbomb->CheckDestoyableObjects(pBomb); }

    void __fastcall DeleteDynamicObj(DynamicObject* pBomb) { m_sbomb->DeleteDynamicObj(pBomb); };
    void __fastcall DeleteStaticObj(GameObject* pObj) { m_sbomb->DeleteStaticObj(pObj); };

    Ground* FindGround() const { m_sbomb->FindGround(); };
    Plane* FindPlane() const { m_sbomb->FindPlane(); };
    LevelGUI* FindLevelGUI() const { m_sbomb->FindLevelGUI(); };
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const { m_sbomb->FindDestoyableGroundObjects(); };
    std::vector<Bomb*> FindAllBombs() const { m_sbomb->FindAllBombs(); };

    void DropBomb() { m_sbomb->DropBomb(); };

    //std::vector<DynamicObject*> vecDynamicObj;
    //std::vector<GameObject*> vecStaticObj;
    //
    //bool exitFlag;

    //uint64_t startTime, finishTime, passedTime;
    //uint16_t bombsNumber, deltaTime, fps;
    //int16_t score;
};

