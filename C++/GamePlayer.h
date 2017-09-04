#pragma once

#include <string>
using namespace std;

#include "Player.h"


class GamePlayer : public Player
{
private:
public:
	GamePlayer(string name);
	int place;
	bool inPenaltyBox;
};
