#include "pch.h"
#include "Paint.h"

using namespace std;

Paint::Paint()
{

}

Paint::Paint(Dryability dryability, string color)
{

}

Dryability Paint::getDryability()
{
	return quickDry;
}

string Paint::getColor()
{
	return "";
}

string Paint::getDescription(int index)
{
	return "";
}

string Paint::getDescriptionAtCurrentIndex()
{
	return "";
}

int Paint::getCurrentIndex()
{
	return -1;
}

void Paint::incrementIndex()
{

}