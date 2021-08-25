#pragma once

#include "Piece.h"

class Pawn : public Piece
{
private:
	bool _isFirstMove;

public:
	Pawn(char letter);
	virtual ~Pawn();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};