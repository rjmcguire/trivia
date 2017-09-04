#pragma once

#include <string>
using namespace std;

class Player
{
private:
public:
	Player(string name);
	string name; // TODO: make private
	string getName();

	int purse;
};
