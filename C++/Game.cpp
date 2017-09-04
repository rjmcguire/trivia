#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;


Game::Game():
playerIndex(0)
{
	for (int i = 0; i < MAX_QUESTIONS; i++)
	{

		ostringstream oss (ostringstream::out);
		oss << "Pop Question " << i;

		popQuestions.push_back(oss.str());

		oss.str("");
		oss << "Science Question " << i;
		scienceQuestions.push_back(oss.str());

		oss.str("");
		oss << "Sports Question " << i;
		sportsQuestions.push_back(oss.str());

		rockQuestions.push_back(createRockQuestion(i));
	}
}

string Game::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf(indexStr, "Rock Question %d", index);
	return indexStr;
}

bool Game::isPlayable()
{
	return (howManyPlayers() >= 2);
}

bool Game::add(string playerName){
	auto player = new GamePlayer(playerName);
	players.push_back(player);

	cout << player->getName() << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	return true;
}

int Game::howManyPlayers()
{
	return players.size();
}

void Game::roll(int roll)
{
	auto player = currentPlayer();

	cout << player->getName() << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if (currentPlayer()->inPenaltyBox)
	{
		if (roll % 2 != 0)
		{
			isGettingOutOfPenaltyBox = true;

			cout << player->getName() << " is getting out of the penalty box" << endl;
			currentPlayer()->move(roll);

			cout << player->getName() << "'s new location is " << currentPlayer()->getPlace() << endl;
			cout << "The category is " << currentCategory() << endl;
			askQuestion();
		}
		else
		{
			cout << player->getName() << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
		}

	}
	else
	{

		currentPlayer()->move(roll);

		cout << player->getName() << "'s new location is " << currentPlayer()->getPlace() << endl;
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
	}

}

void Game::askQuestion()
{
	if (currentCategory() == "Pop")
	{
		cout << popQuestions.front() << endl;
		popQuestions.pop_front();
	}
	if (currentCategory() == "Science")
	{
		cout << scienceQuestions.front() << endl;
		scienceQuestions.pop_front();
	}
	if (currentCategory() == "Sports")
	{
		cout << sportsQuestions.front() << endl;
		sportsQuestions.pop_front();
	}
	if (currentCategory() == "Rock")
	{
		cout << rockQuestions.front() << endl;
		rockQuestions.pop_front();
	}
}


string Game::currentCategory()
{
	auto place = currentPlayer()->getPlace();
	if (place == 0 || place == 4 || place == 8) return "Pop";
	if (place == 1 || place == 5 || place == 9) return "Science";
	if (place == 2 || place == 6 || place == 10) return "Sports";
	return "Rock";
}

bool Game::wasCorrectlyAnswered()
{
	if (currentPlayer()->inPenaltyBox)
	{
		if (isGettingOutOfPenaltyBox)
		{
			cout << "Answer was correct!!!!" << endl;
			currentPlayer()->purse++;
			cout << currentPlayer()->getName()
			     << " now has "
			     << currentPlayer()->purse
				<<  " Gold Coins." << endl;

			bool winner = didPlayerWin();
			nextPlayer();

			return winner;
		}
		else
		{
			nextPlayer();
			return true;
		}



	}
	else
	{

		cout << "Answer was corrent!!!!" << endl;
		currentPlayer()->purse++;
		cout << currentPlayer()->getName()
				<< " now has "
				<< currentPlayer()->purse
			<< " Gold Coins." << endl;

		bool winner = didPlayerWin();
		nextPlayer();

		return winner;
	}
}

bool Game::wrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;
	cout << currentPlayer()->getName() + " was sent to the penalty box" << endl;
	currentPlayer()->inPenaltyBox = true;

	nextPlayer();
	return true;
}


bool Game::didPlayerWin()
{
	return !(currentPlayer()->purse == 6);
}

void Game::nextPlayer() {
	playerIndex++;
	if (playerIndex == players.size()) playerIndex = 0;
}

GamePlayer* Game::currentPlayer() {
	return players[playerIndex];
}
