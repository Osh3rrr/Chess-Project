#include "Pawn.h"

Pawn::Pawn(char letter)
{
    this->_sign = letter;
    this->_isFirstMove = true;
}

Pawn::~Pawn()
{
}

string Pawn::checkIfMoveIsValid(Board *board, string move, bool playerTurn)
{
    string src = string() + move[0] + move[1];
    string dst = string() + move[2] + move[3];

    string moveValid = "0";

    if (!isDstSqureClear(board, string() + move[2] + move[3]) && !canEat(board, move, playerTurn))
    {
        return "3"; // invalid move, in the target square there is a tool of the current player
    }

    else if (!checkIfSrcSquareRight(board, move, playerTurn))
    {
        return "2"; // invalid move, In the source square there is no tool of the current player
    }

    else if (!src.compare(dst))
    {
        return "7";
    }

    else if (playerTurn == false) // if white player
    {
        if (_isFirstMove)
        {
            this->_isFirstMove = false;
            if (src[0] == dst[0] && src[1] == dst[1] + 2 && isDstSqureClear(board, dst)) // if trying to go two squares in first move
            {
                return "0";
            }

            else if (src[1] == dst[1] + 1) // if trying to move 1 square foward
            {
                if ((src[0] - 1 == dst[0] || src[0] + 1 == dst[0]) && canEat(board, move, playerTurn)) // if player trying to move diagonal and can eat
                {
                    return "0";
                }
                else if(src[0] == dst[0] && isDstSqureClear(board, dst))
                {
                    return "0";
                }
                else
                {
                    this->_isFirstMove = true;
                    return "6";
                }
            }

            else
            {
                this->_isFirstMove = true;
                return "6";
            }
        }

        else if (src[1] == dst[1] + 1)
        {
            if ((src[0] - 1 == dst[0] || src[0] + 1 == dst[0]) && canEat(board, move, playerTurn)) // if player trying to move diagonal and can eat
            {
                return "0";
            }

            else if(src[0] == dst[0] && isDstSqureClear(board, dst))
            {
                return "0";
            }

            else
            {
                return "6";
            }
        }

        else
        {
            return "6";
        }
    }

    else if(playerTurn == true) // if black player
    {
        if (_isFirstMove)
        {
            this->_isFirstMove = false;
            if (src[0] == dst[0] && src[1] == dst[1] - 2 && isDstSqureClear(board, dst)) // if trying to go two squares in first move
            {
                return "0";
            }

            else if (src[1] == dst[1] - 1) // if trying to move 1 square foward
            {
                if ((src[0] - 1 == dst[0] || src[0] + 1 == dst[0]) && canEat(board, move, playerTurn)) // if player trying to move diagonal and can eat
                {
                    return "0";
                }
                else if(src[0] == dst[0] && isDstSqureClear(board, dst))
                {
                    return "0";
                }
                else
                {
                    this->_isFirstMove = true;
                    return "6";
                }
            }
            else
            {
                this->_isFirstMove = true;
                return "6";
            }
        }

        else if (src[1] == dst[1] - 1)
        {
            if ((src[0] - 1 == dst[0] || src[0] + 1 == dst[0]) && canEat(board, move, playerTurn)) // if player trying to move diagonal and can eat
            {
                return "0";
            }

            else if(src[0] == dst[0] && isDstSqureClear(board, dst))
            {
                return "0";
            }

            else
            {
                return "6";
            }
        }
        else
        {
            return "6";
        }
    }

    else
    {
        return "6";
    }
}


