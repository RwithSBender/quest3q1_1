#pragma once
#include <vector>
#include <string>
#include "DynamicObject.h"
#include "SBomber.h"
#include "FileLoggerSingleton.h"

using namespace std;

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
};


//void __fastcall DeleteDynamicObj(DynamicObject* pBomb);
//void __fastcall DeleteStaticObj(GameObject* pObj);
//void DropBomb();

class DeleteDynamicO : public Command
{
	DynamicObject* pBomb;
	vector<DynamicObject*>* vecDynamicObj;
public:
	DeleteDynamicO(DynamicObject* _pBomb, vector<DynamicObject*>* _vecDynamicObj) {
		pBomb = _pBomb;  vecDynamicObj = _vecDynamicObj;}
	void Execute()
	{
		auto it = vecDynamicObj->begin();
		for (; it != vecDynamicObj->end(); it++)
		{
			if (*it == pBomb)
			{
				vecDynamicObj->erase(it);
				break;
			}
		}
	}
};

class DeleteStaticO : public Command
{
	GameObject* pObj;
	vector<GameObject*>* vecStaticObj;
public:
	DeleteStaticO(GameObject* _pObj, vector<GameObject*>* _vecStaticObj) {
		pObj = _pObj;  vecStaticObj = _vecStaticObj;
	}
	void Execute()
	{
		auto it = vecStaticObj->begin();
		for (; it != vecStaticObj->end(); it++)
		{
			if (*it == pObj)
			{
				vecStaticObj->erase(it);
				break;
			}
		}
	}
};

class DropBom : public Command
{
//	DynamicObject* pBomb;
	uint16_t* bombNumber;
	int16_t* score;
	Plane* pPlane;
	vector<DynamicObject*>* vecDynamicObj;
public:
	DropBom(Plane* _plane, vector<DynamicObject*>* _vecDynamicObj, uint16_t* _bombNumber, int16_t* _score)
	{
		pPlane = _plane;
		vecDynamicObj = _vecDynamicObj;
		bombNumber = _bombNumber;
		score = _score;
	}
	void Execute()
	{
		if (*bombNumber > 0)
		{
			FileLoggerSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

			double x = pPlane->GetX() + 4;
			double y = pPlane->GetY() + 2;

			Bomb* pBomb = new Bomb;
			pBomb->SetDirection(0.3, 1);
			pBomb->SetSpeed(2);
			pBomb->SetPos(x, y);
			pBomb->SetWidth(SMALL_CRATER_SIZE);

			vecDynamicObj->push_back(pBomb);
			(*bombNumber)--;
			score -= Bomb::BombCost;
		}
	}
};


class Invoker
{
	vector<Command*> DoneCommands;
	Command* pCommand;
public:
	Invoker() : pCommand(nullptr) { }
	~Invoker()
	{
		for (Command* ptr : DoneCommands)
		{
			delete ptr;
		}
	}
	void DeleteDynamic(DynamicObject* pBomb, std::vector<DynamicObject*>* vecDynamicObj)
	{
		pCommand = new DeleteDynamicO(pBomb, vecDynamicObj );
		pCommand->Execute();
		DoneCommands.push_back(pCommand);
	}
	void DeleteStatic(GameObject* pObj, std::vector<GameObject*>* vecStaticObj)
	{
		pCommand = new DeleteStaticO(pObj, vecStaticObj);
		pCommand->Execute();
		DoneCommands.push_back(pCommand);
	}
	void DropBomb(Plane* plane, vector<DynamicObject*>* vecDynamicObj, uint16_t* bombNumber, int16_t* score)
	{
		pCommand = new DropBom(plane, vecDynamicObj, bombNumber, score);
		pCommand->Execute();
		DoneCommands.push_back(pCommand);
	}
};