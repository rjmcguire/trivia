#include <string>
using namespace std;

#include "GamePlayer.h"


GamePlayer::GamePlayer(string name):
Player(name),
place(0),
inPenaltyBox(0)
{

}

void GamePlayer::move(int movePlaces) {
	place += movePlaces;
	if (place > 11) place -= 12;
}

int GamePlayer::getPlace() {
	return place;
}