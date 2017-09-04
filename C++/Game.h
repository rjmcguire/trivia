#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef GAME_H_
#define GAME_H_

#define MAX_QUESTIONS 50
#define MAX_PLAYERS 6
#define WINNING_CREDIT 6

#include "GamePlayer.h"


class Game{

		private:
			vector<GamePlayer*> players;

			list<string> popQuestions;
			list<string> scienceQuestions;
			list<string> sportsQuestions;
			list<string> rockQuestions;

			GamePlayer *currentPlayer();
			int playerIndex;
			bool isGettingOutOfPenaltyBox;

public:
	Game();
	string createRockQuestion(int index);
	bool isPlayable();
	bool add(string playerName);
	void nextPlayer();


	int howManyPlayers();
	void roll(int roll);

	private:
		void askQuestion();
		string currentCategory();

				public:
					bool wasCorrectlyAnswered();
					bool wrongAnswer();

private:
	bool didPlayerWin();
};

#endif /* GAME_H_ */
