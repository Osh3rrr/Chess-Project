#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(char letter);
	virtual ~Queen();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};