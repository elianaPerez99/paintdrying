#pragma once
#include "Paint.h"
#include <string>
#include <fstream>

using namespace std;

class Drier
{
public:
	Drier();
	void getInput(); //gets the input from the player
	void createPaintFromFile(string filename);
	void printOutNormalDescription();
	void printOutBackwardsDescription();
	Paint getPaint();
private:
	Paint paint;
};