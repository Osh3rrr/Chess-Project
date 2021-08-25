#include "Turn.h"
#include "Pipe.h"
#include <iostream>
#include <thread>

Turn::Turn()
{
	this->_playerTurn = false; // false = white, true = black players.
}

Turn::~Turn()
{
}

bool Turn::getPlayerTurn()
{
	return this->_playerTurn;
}


void Turn::changeTurn()
{
	this->_playerTurn = !(this->_playerTurn);
}
