#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(char letter);
	virtual ~Bishop();
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn);
};