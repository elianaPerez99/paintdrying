#pragma once
#include "Paint.h"
#include <string>
#include <fstream>

class Drier
{
public:
	Drier();
	void getInput(); //gets the input from the player
	bool createPaintFromFile(string filename); //returns true if working, returns false if something goes wrong
	string printOutNormalDescription();
	string printOutBackwardsDescription();
	Paint getPaint();
private:
	Paint paint;
};