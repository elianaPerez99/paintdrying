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
	Paint(Dryability, string);
	Dryability getDryability();
	string getColor();
	string getDescription(int index);
	string getDescriptionAtCurrentIndex();
	int getCurrentIndex();
	void incrementIndex();
private:
	Dryability type;
	string color;
	string descriptions[3];
	int currentIndex;
	
};

