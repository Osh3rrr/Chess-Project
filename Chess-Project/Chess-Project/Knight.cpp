#include "Knight.h"

Knight::Knight(char letter)
{
    this->_sign = letter; // 'n' / 'N'
}

Knight::~Knight()
{
}

string Knight::checkIfMoveIsValid(Board *board, string move, bool playerTurn)
{
    string srcMove = string() + move[0] + move[1];
    string dstMove = string() + move[2] + move[3];

    if (!checkIfSrcSquareRight(board, move, playerTurn))
    {
        return "2";
    }

    else if (!srcMove.compare(dstMove))
    {
        return "7";
    }

    else if ( ((srcMove.at(0) == dstMove.at(0) + 1 || srcMove.at(0) == dstMove.at(0) - 1) && (srcMove.at(1) == dstMove.at(1) - 2 || srcMove.at(1) == dstMove.at(1) + 2)) || ((srcMove.at(0) == dstMove.at(0) - 2 || srcMove.at(0) == dstMove.at(0) + 2) && (srcMove.at(1) == dstMove.at(1) + 1 || srcMove.at(1) == dstMove.at(1) - 1)))
    {
        if (!isDstSqureClear(board, dstMove) && !canEat(board, move, playerTurn))
        {
            return "3";
        }

        else if (!isDstSqureClear(board, dstMove) && canEat(board, move, playerTurn))
        {
            return "0";
        }

        return "0";
    }

    else
    {
        return "6";
    }
}


