#pragma once
#include "Piece.h"

class Knight : public Piece
{

public:
	Knight(char letter);
	virtual ~Knight();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};