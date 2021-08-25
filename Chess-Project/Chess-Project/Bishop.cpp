#include "Bishop.h"
#include <iostream>

Bishop::Bishop(char letter)
{
    this->_sign = letter;
}

Bishop::~Bishop()
{
}

string Bishop::checkIfMoveIsValid(Board *board, string move, bool playerTurn)
{
    int i = 0;
    char ch1 = '0';
    char ch2 = '0';
    string moveValid = "0";
    string srcMove = string() + move[0] + move[1];
    string dstMove = string() + move[2] + move[3];
    string wayToDst = "";

    if (!isDstSqureClear(board, string() + move[2] + move[3]) && !canEat(board, move, playerTurn))
    {
        moveValid = "3";// invalid move, in the target square there is a tool of the current player
    }
    else if (!checkIfSrcSquareRight(board, move, playerTurn))
    {
        moveValid = "2";// invalid move, In the source square there is no tool of the current player
    }
    else if (move[0] == move[2] && move[1] == move[3])
    {
        moveValid = "7";// invalid move, dest square and source square are the same
    }
    else if (srcMove[0] - dstMove[0] == srcMove[1] - dstMove[1])
    {
        if (srcMove[0] - dstMove[0] < 0) //moving up right
        {
            for (i = dstMove[0] - srcMove[0] - 1; i > 0; i--)
            {
                ch1 = srcMove[0] + i;
                ch2 = srcMove[1] + i;
                wayToDst = string() + ch1 + ch2;
                std::cout << wayToDst << std::endl;
                if (board->getSquare(wayToDst)->getSign() != '#')
                {
                    moveValid = "6";// invalid move, invalid movement of tool
                }

            }
        }
        else if (srcMove[0] - dstMove[0] > 0) //moving down left
        {
            for (i = srcMove[0] - dstMove[0] - 1; i > 0; i--)
            {
                ch1 = srcMove[0] - i;
                ch2 = srcMove[1] - i;
                wayToDst = string() + ch1 + ch2;
                std::cout << wayToDst << std::endl;
                if (board->getSquare(wayToDst)->getSign() != '#')
                {
                    moveValid = "6";// invalid move, invalid movement of tool
                }

            }
        }
        else
        {
            moveValid = "6";// invalid move, invalid movement of tool
        }

    }
    else if (srcMove[0] - dstMove[0] == -(srcMove[1] - dstMove[1]))
    {
        if (srcMove[0] - dstMove[0] < 0) //moving down right
        {
            for (i = dstMove[0] - srcMove[0] - 1; i > 0; i--)
            {
                ch1 = srcMove[0] + i;
                ch2 = srcMove[1] - i;
                wayToDst = string() + ch1 + ch2;
                std::cout << wayToDst << std::endl;
                if (board->getSquare(wayToDst)->getSign() != '#')
                {
                    moveValid = "6";// invalid move, invalid movement of tool
                }

            }
        }
        else if (srcMove[0] - dstMove[0] > 0) //moving up left
        {
            for (i = srcMove[0] - dstMove[0] - 1; i > 0; i--)
            {
                ch1 = srcMove[0] - i;
                ch2 = srcMove[1] + i;
                wayToDst = string() + ch1 + ch2;
                std::cout << wayToDst << std::endl;
                if (board->getSquare(wayToDst)->getSign() != '#')
                {
                    moveValid = "6";// invalid move, invalid movement of tool
                }

            }
        }
        else
        {
            moveValid = "6";// invalid move, invalid movement of tool
        }

    }
    else
    {
        moveValid = "6";// invalid move, invalid movement of tool
    }
    return moveValid;
}
