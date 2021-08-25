#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen(char letter)
{
    this->_sign = letter;
}

Queen::~Queen()
{
}

string Queen::checkIfMoveIsValid(Board *board, string move, bool playerTurn)
{
    Rook r('r');
    Bishop b('b');

    string validMoveRook = "", validMoveBishop = "";

    validMoveRook = r.checkIfMoveIsValid(board, move, playerTurn);
    validMoveBishop = b.checkIfMoveIsValid(board, move, playerTurn);

    if (!validMoveBishop.compare("0") || !validMoveRook.compare("0"))
    {
        return "0";
    }

    else if (validMoveBishop.compare("0"))
    {
        return validMoveBishop;
    }

    else if (validMoveRook.compare("0"))
    {
        return validMoveRook;
    }

    else if (validMoveRook.compare("0") && validMoveBishop.compare("0"))
    {
        if (!validMoveRook.compare(validMoveBishop))
        {
            return validMoveBishop;
        }

        else
        {
            return "6";
        }
    }
}
