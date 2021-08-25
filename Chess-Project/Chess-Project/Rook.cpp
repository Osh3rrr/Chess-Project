#include "Rook.h"
#include "Turn.h"
#include <iostream>

Rook::Rook(char letter)
{
    this->_sign = letter;
}

Rook::~Rook()
{
}

string Rook::checkIfMoveIsValid(Board *board, string move, bool playerTurn)
{
    int i = 0;
    string srcMove = string() + move[0] + move[1];
    string dstMove = string() + move[2] + move[3];
    string wayToDst = "";

    if (!isDstSqureClear(board, dstMove) && !canEat(board, move, playerTurn))
    {
        return "3";
    }

    //else if (!isDstSqureClear(board, dstMove) && canEat(board, move, playerTurn))
    //{
    //    return "0";
    //}


    if (!checkIfSrcSquareRight(board, srcMove, playerTurn))
    {
        return "2";
    }

    if (!srcMove.compare(dstMove))
    {
        return "7";
    }

    else
    {
        if ( (srcMove.at(0) != dstMove.at(0)) && (srcMove.at(1) == dstMove.at(1)) ) // if the player moving sideways
        {

            if (srcMove.at(0) < dstMove.at(0)) // moving right
            {
                for (i = 1 ; i < dstMove.at(0) - srcMove.at(0); i++) // running all over the squares to dst
                {
                    wayToDst = string() + char(srcMove.at(0) + i) + srcMove.at(1);

                    if (board->getSquare(wayToDst)->getSign() != '#')
                    {
                        return "6";
                    }
                }

                return "0";
            }

            else // moving left
            {
                for (i = 1 ; i < srcMove.at(0) - dstMove.at(0); i++) // running all over the squares to dst
                {
                    wayToDst = string() + char(srcMove.at(0) - i) + srcMove.at(1);

                    if (board->getSquare(wayToDst)->getSign() != '#')
                    {
                        return "6";
                    }
                }

                return "0";
            }
        }

        else if( (srcMove.at(0) == dstMove.at(0)) && (srcMove.at(1) != dstMove.at(1)) ) // if the player go up or down
        {
            if (srcMove.at(1) < dstMove.at(1)) // moving up
            {
                for (i = 1; i < dstMove.at(1) - srcMove.at(1); i++) // running all over the squares to dst
                {
                    wayToDst = string() + srcMove.at(0) + char(srcMove.at(1) + i);

                    if (board->getSquare(wayToDst)->getSign() != '#')
                    {
                        return "6";
                    }
                }

                return "0";
            }

            else // moving down
            {
                for (i = 1; i < srcMove.at(1) - dstMove.at(1); i++)
                {
                    wayToDst = string() + srcMove.at(0) + char(srcMove.at(1) - i);

                    if (board->getSquare(wayToDst)->getSign() != '#')
                    {
                        return "6";
                    }
                }

                return "0";
            }
        }

        else
        {
            return "6";
        }
    }

}
