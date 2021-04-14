#pragma once
#include <string>
#include <array>
using namespace std;

enum Dryability
{
	quickDry = 0,
	normal = 1,
	slowDry = 2
};


class Paint
{
public:
	Paint();
	Dryability type;
	string color;
	string descriptions[3];
	int currentIndex;
	string getDescriptionAtCurrentIndex();
};


