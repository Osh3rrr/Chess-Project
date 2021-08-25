#pragma once

#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(char letter);
	virtual ~Rook();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};