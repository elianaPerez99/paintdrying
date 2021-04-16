#include "pch.h"
#include "Drier.h"
#include <vector>

using namespace std;

Drier::Drier() {
}

bool Drier::createPaintFromFile(string filename) 
{
	ifstream file;
	string currentLine;
	vector<string> contents;
	Dryability dryability;
	file.open(filename);
	if (file) {
		while (getline(file, currentLine))
			contents.push_back(currentLine);
		if (contents.size() != 2)
			return false;
		else
		{
			if (contents[0] == "normal")
				dryability = normal;
			else if (contents[0] == "quickDry")
				dryability = quickDry;
			else if (contents[0] == "slowDry")
				dryability = slowDry;
			else
				return false;

			customPaint = Paint(dryability, contents[1]);
		}
	}
	else
		return false;
	return true;
}

string Drier::printOutBackwardsDescription()
{
	string retval;
	if (paint.getCurrentIndex() == 0)
	{
		retval = paint.getDescription(2);
		paint.incrementIndex();
	}
	else if (paint.getCurrentIndex() == 2)
	{
		retval = paint.getDescription(0);
		paint.setCurrentIndex(0);
	}
	else if (paint.getCurrentIndex() == 1)
	{
		retval = paint.getDescription(1);
		paint.incrementIndex();
	}
	return retval;
}

string Drier::printOutNormalDescription()
{
	string retval = paint.getDescriptionAtCurrentIndex();
	paint.incrementIndex();
	return retval;
}

string Drier::printOutCustomDescription()
{
	string retval = customPaint.getDescriptionAtCurrentIndex();
	customPaint.incrementIndex();
	return retval;
}

Paint Drier::getCustomPaint()
{
	return customPaint;
}

void Drier::printPaint()
{
	cout << printOutNormalDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
	cin.ignore();
	cout << printOutNormalDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
	cout << printOutNormalDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
}

void Drier::printPaintReverse()
{
	cout << printOutBackwardsDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
	cin.ignore();
	cout << printOutBackwardsDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
	cout << printOutBackwardsDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
}

void Drier::printCustomPaint()
{
	cout << printOutCustomDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
	cin.ignore();
	cout << printOutCustomDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
	cout << printOutCustomDescription() << endl;
	cout << "Press enter to continue";
	cin.ignore();
}

void Drier::getInput()
{
	bool toContinue = true;
	string userInput;
	while (toContinue)
	{
		cout << "What would you like to do?" << endl;
		cout << "Type (d) to watch the default paint drying" << endl;
		cout << "Type (c) to input a filename that includes details for a custom type of paint, and then watch it dry" << endl;
		cout << "Type (r) to watch the default paint dry in reverse" << endl;
		cout << "Type (e) to exit the program and view the tests" << endl;
		cin >> userInput;
		cout << endl;
		if (userInput == "d" || userInput == "(d)")
			printPaint();
		else if (userInput == "c" || userInput == "(c)")
		{
			cout << "Please input the name of a valid paint file (for an example of a valid paint file, check customPaint.txt" << endl;
			cin >> userInput;
			cout << endl;
			if (createPaintFromFile(userInput))
				printCustomPaint();
			else
				cout << "Invalid paint file" << endl;
		}
		else if (userInput == "r" || userInput == "(r)")
			printPaintReverse();
		else if (userInput == "e" || userInput == "(e)")
			break;
		else
			cout << "Invalid input, please try again." << endl;
	}
}
