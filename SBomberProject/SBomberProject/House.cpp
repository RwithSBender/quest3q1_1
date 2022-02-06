
#include <iostream>

#include "House.h"
#include "MyTools.h"
#include "ScreenSingleton.h"

using namespace std;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	ScreenSingleton::getInstance().SetColor(CC_Yellow);
	ScreenSingleton::getInstance().GotoXY(x, y - 5);
	cout << look[0];
	ScreenSingleton::getInstance().GotoXY(x, y - 4);
	cout << look[1];
	ScreenSingleton::getInstance().GotoXY(x, y - 3);
	cout << look[2];
	ScreenSingleton::getInstance().GotoXY(x, y - 2);
	cout << look[3];
	ScreenSingleton::getInstance().GotoXY(x, y - 1);
	cout << look[4];
	ScreenSingleton::getInstance().GotoXY(x, y);
	cout << look[5];
}


//char look[7][14];
HouseBuilderA::HouseBuilderA(House *h)
	{
		hous = h;
		fillRoof();
		fillWall();
		fillWindow();
		fillÑhimney();
	}
	void HouseBuilderA::fillWall()
	{
		strcpy_s(hous->look[2], "############");
		strcpy_s(hous->look[3], "##        ##");
		strcpy_s(hous->look[4], "##        ##");
		strcpy_s(hous->look[5], "############");
	};
	void HouseBuilderA::fillRoof()
	{
		strcpy_s(hous->look[0], "  ########  ");
		strcpy_s(hous->look[1], "##        ##");
	};
	void HouseBuilderA::fillWindow()
	{
		hous->look[3][6] = '@';
		hous->look[3][7] = '@';
		hous->look[4][6] = '@';
		hous->look[4][7] = '@';
	};
	void HouseBuilderA::fillÑhimney()
	{
		hous->look[0][10] = '|';
		hous->look[0][11] = '|';
	};
