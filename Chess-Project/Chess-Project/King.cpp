#include "King.h"
#include <iostream>

King::King(char letter)
{
	this->_sign = letter;
}

King::~King()
{
}

string King::checkIfMoveIsValid(Board *board, string move, bool playerTurn)
{
    string moveValid = "0"; // valid move!
    
    if (!isDstSqureClear(board, string() + move[2] + move[3]) && !canEat(board, move, playerTurn))
    {
        moveValid = "3"; // invalid move, in the target square there is a tool of the current player
    }
    else if (!checkIfSrcSquareRight(board, move, playerTurn))
    {
        moveValid = "2"; // invalid move, In the source square there is no tool of the current player
    }
    else if (!((move[0] + 1 == move[2] && move[1] == move[3]) || (move[2] + 1 == move[0] && move[1] == move[3])
        || (move[1] + 1 == move[3] && move[0] == move[2]) || (move[3] + 1 == move[1] && move[0] == move[2])
        || (move[0] + 1 == move[2] && move[1] + 1 == move[3]) || (move[0] + 1 == move[2] && move[1] == move[3] + 1)
        || (move[0] == move[2] + 1 && move[1] + 1 == move[3]) || (move[0] == move[2] + 1 && move[1] == move[3] + 1)))
    {
        moveValid = "6"; // invalid move, invalid movement of tool
    }
    else if (move[0] == move[2] && move[1] == move[3])
    {
        moveValid = "7"; // invalid move, dest square and source square are the same
    }
	return moveValid;
}

