#pragma once

#include "Piece.h"
#include <iostream>

Piece::Piece()
{
}
Piece::~Piece()
{
}

bool Piece::isDstSqureClear(Board *board, string movement)
{
	if (board->getSquare(string() + movement[0] + movement[1])->getSign() == '#')
	{
		return true;
	}

	return false;
}

bool Piece::checkIfSrcSquareRight(Board *board, string movement, bool playerTurn)
{
	if (board->getSquare(string() + movement[0] + movement[1])->getSign() == '#')
	{
		return false;
	}
	else if (playerTurn == false && board->getSquare(string() + movement[0] + movement[1])->getSign() >= 'a' && board->getSquare(string() + movement[0] + movement[1])->getSign() <= 'z')
	{
		return false;
	}
	else if (playerTurn == true && board->getSquare(string() + movement[0] + movement[1])->getSign() >= 'A' && board->getSquare(string() + movement[0] + movement[1])->getSign() <= 'Z')
	{
		return false;
	}
	return true;
}

bool Piece::canEat(Board* board, string movement, bool playerTurn)
{
	if (playerTurn == false && board->getSquare(string() + movement[2] + movement[3])->getSign() >= 97)
	{
		return true;
	}

	if (playerTurn == true && board->getSquare(string() + movement[2] + movement[3])->getSign() < 97 && board->getSquare(string() + movement[2] + movement[3])->getSign() != '#')
	{
		return true;
	}

	return false;
}

char Piece::getSign()
{
	return this->_sign;
}
