#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include <vector>
#include "LevelGUI.h"

//class AbstractLevelGUI;

class Mediator {
public:
	void addGUI( AbstractLevelGUI* pgui) { pGUI = pgui; }
	void AddMessage(std::string& message) { pGUI->addMessage(message); };
	AbstractLevelGUI* pGUI;
};

class Tank : public DestroyableGroundObject
{
public:
	Tank() { mediator = new Mediator; }

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void add_gui(AbstractLevelGUI* pgui) { 
		
		mediator->pGUI = (pgui);
	};
private:

	const uint16_t score = 30;
	Mediator* mediator;
};

