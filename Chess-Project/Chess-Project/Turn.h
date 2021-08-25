#pragma once
#include <string>

using namespace std;

class Turn
{
private:
	bool _playerTurn;

public:
	Turn(); // C'tor
	~Turn(); // D'tor
	bool getPlayerTurn(); // Return the turn of the current player
	void changeTurn(); // changing the player turn
};
