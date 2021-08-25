#pragma once
#include <string>
#include "Board.h"
#include "Turn.h"

using namespace std;

class Board;
class Piece
{
protected:
	char _sign;
public:
	Piece(); // c'tor
	virtual ~Piece();
	bool isDstSqureClear(Board *board, string movement); // return if the dst squre clear 
	bool checkIfSrcSquareRight(Board *board, string movement, bool playerTurn);
	virtual string checkIfMoveIsValid(Board *board, string move, bool playerTurn) = 0;
	bool canEat(Board* board, string movement, bool playerTurn);
	char getSign();
};