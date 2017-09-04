#include <string>
using namespace std;

#include "Player.h"


Player::Player(string name):
name(name)
{
	
}

string Player::getName() {
	return this->name;
}


void Player::addCredits(int credits) {
	purse++;
}

int Player::getCredits() {
	return purse;
}