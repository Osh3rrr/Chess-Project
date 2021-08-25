#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(char letter);
	virtual ~King();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};