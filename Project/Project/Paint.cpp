#include "pch.h"
#include "Paint.h"

using namespace std;

Paint::Paint()
{
	type = normal;
	mColor = "white";
	setUpDescriptions();
	currentIndex = 0;
}

Paint::Paint(Dryability dryability, string color)
{
	type = dryability;
	mColor = color;
	setUpDescriptions();
	currentIndex = 0;
}

Dryability Paint::getDryability()
{
	return type;
}

string Paint::getColor()
{
	return mColor;
}

void Paint::setUpDescriptions()
{
	switch (type)
	{
	case quickDry:
	{
		descriptions[0] = "The paint is moist.";
		descriptions[1] = "The paint is dry.";
		descriptions[2] = "The paint is ready for a second coat.";
		break;
	}
	case normal:
	{
		descriptions[0] = "The paint is wet.";
		descriptions[1] = "The paint is moist.";
		descriptions[2] = "The paint is dry.";
		break;
	}
	case slowDry:
	{
		descriptions[0] = "The paint is very wet. It glimmers in the sunlight.";
		descriptions[1] = "The paint is slightly wet. It is shiny.";
		descriptions[2] = "The paint is moist.";
		break;
	}
	default:
	{
		descriptions[0] = "The paint is wet.";
		descriptions[1] = "The paint is wet.";
		descriptions[2] = "The paint is wet.";
		break;
	}
	}
}
string Paint::getDescription(int index)
{
	if (index <= 2 && index >= 0)
		return descriptions[index];
	else
		return "Invalid index for description";

}

string Paint::getDescriptionAtCurrentIndex()
{
	return descriptions[currentIndex];
}

int Paint::getCurrentIndex()
{
	return currentIndex;
}

void Paint::incrementIndex()
{
	if (currentIndex < 2)
	{
		currentIndex++;
	}
	else
	{
		currentIndex = 0;
	}
}

void Paint::decrementIndex()
{
	if (currentIndex > 0)
	{
		currentIndex--;
	}
	else
	{
		currentIndex = 2;
	}
}

void Paint::setCurrentIndex(int index)
{
	currentIndex = index;
}