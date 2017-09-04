#pragma once

#include <string>
using namespace std;

class Player
{
private:
	int purse;
	string name;

public:
	Player(string name);
	string getName();
	void addCredits(int credit);
	int getCredits();
};
