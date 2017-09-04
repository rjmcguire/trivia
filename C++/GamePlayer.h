#pragma once

#include <string>
using namespace std;

#include "Player.h"


class GamePlayer : public Player
{
private:
	int place;

public:
	GamePlayer(string name);
	bool inPenaltyBox;

	void move(int movePlaces);
	int getPlace();
};
