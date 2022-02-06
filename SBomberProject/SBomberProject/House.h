#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:
	bool __fastcall isInside(double x1, double x2) const override;
	inline uint16_t GetScore() const override { return score; }
	void Draw() const override;
private:
	char look[7][14];
	const uint16_t score = 40;
	friend class HouseBuilderA;
};

class HouseBuilder
{
protected:
	House* hous;
public:
	HouseBuilder() {};
private:
	virtual void fillWall() = 0;
	virtual void fillRoof() = 0;
	virtual void fillWindow() = 0;
	virtual void fill—himney() = 0;
};

class HouseBuilderA : public HouseBuilder
{
public:
	HouseBuilderA(House* h);
private:
	void fillWall();
	void fillRoof();
	void fillWindow();
	void fill—himney();
};

