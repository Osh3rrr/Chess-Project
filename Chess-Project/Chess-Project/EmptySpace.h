#pragma once

#include "Piece.h"

class EmptySpace : public Piece
{
public:
	EmptySpace();
	virtual ~EmptySpace();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};