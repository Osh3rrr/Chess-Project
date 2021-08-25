#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "EmptySpace.h"
#include <iostream>


Board::Board()
{
	this->_start = "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0";
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 7; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			switch (_start[k])
			{
			case WHITE_ROOK:
				this->_board[i][j] = new Rook(WHITE_ROOK);
				break;
			case BLACK_ROOK:
				this->_board[i][j] = new Rook(BLACK_ROOK);
				break;
			case WHITE_BISHOP:
				this->_board[i][j] = new Bishop(WHITE_BISHOP);
				break;
			case BLACK_BISHOP:
				this->_board[i][j] = new Bishop(BLACK_BISHOP);
				break;
			case WHITE_KING:
				this->_board[i][j] = new King(WHITE_KING);
				break;
			case BLACK_KING:
				this->_board[i][j] = new King(BLACK_KING);
				break;
			case WHITE_PAWN:
				this->_board[i][j] = new Pawn(WHITE_PAWN);
				break;
			case BLACK_PAWN:
				this->_board[i][j] = new Pawn(BLACK_PAWN);
				break;
			case WHITE_KNIGHT:
				this->_board[i][j] = new Knight(WHITE_KNIGHT);
				break;
			case BLACK_KNIGHT:
				this->_board[i][j] = new Knight(BLACK_KNIGHT);
				break;
			case WHITE_QUEEN:
				this->_board[i][j] = new Queen(WHITE_QUEEN);
				break;
			case BLACK_QUEEN:
				this->_board[i][j] = new Queen(BLACK_QUEEN);
				break;
			case EMPTY_SPACE:
				this->_board[i][j] = new EmptySpace();
				break;
			}
			k++;
		}
	}
}

Board::~Board()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_SIZE; i++)
	{
		for (j = 0; j < ROW_SIZE; j++)
		{
			delete this->_board[i][j];
		}
	}

}

void Board::move(string whatMove)
{
	int rowSrc = getRow(whatMove[0]);
	int colSrc = getCol(whatMove[1]);
	int rowDst = getRow(whatMove[2]);
	int colDst = getCol(whatMove[3]);

	Piece* emptySpace = new EmptySpace();
	
	this->_board[colDst][rowDst] = getSquare(whatMove); // move
	//delete this->_board[colSrc][rowSrc];
	this->_board[colSrc][rowSrc] = emptySpace;
}

Piece* Board::getSquare(string square)
{
	return this->_board[getCol(square.at(1))][getRow(square.at(0))];
}

int Board::getRow(char square)
{
	return (square - 'a');
}

int Board::getCol(char square)
{
	return (square - '1');
}

bool Board::isPlayerCheckedHimself(bool whosTurn)
{
	int i = 0;
	int j = 0;
	bool playerCheckedHimself = false;
	bool isCheck = true;
	string newMovement = "00";
	newMovement += findKingSquare(whosTurn);

	for (i = 0; i < ROW_SIZE; i++)
	{
		for (j = 0; j < COL_SIZE; j++)
		{
			newMovement[0] = static_cast<char>(i + 'a');
			newMovement[1] = static_cast<char>(j + '1');
			if (_board[j][i]->checkIfMoveIsValid(this, newMovement, whosTurn)[0] == '0' || _board[j][i]->checkIfMoveIsValid(this, newMovement, !whosTurn)[0] == '0')
			{
				return true;
			}
			/*if (!whosTurn) // if white turn
			{
				if (getSquare(string() + newMovement[0] + newMovement[1])->getSign() <= 'z' && getSquare(string() + newMovement[0] + newMovement[1])->getSign() >= 'a') // validate it's black player 
				{
					if (_board[j][i]->checkIfMoveIsValid(this, newMovement, whosTurn)[0] == '0')
					{
						return true;
					}
				}
			}
			
			else
			{
				if (getSquare(string() + newMovement[0] + newMovement[1])->getSign() <= 'Z' && getSquare(string() + newMovement[0] + newMovement[1])->getSign() >= 'A')
				{
					if (_board[j][i]->checkIfMoveIsValid(this, newMovement, whosTurn)[0] == '0')
					{
						return true;
					}
				}
			}*/
		}
	}
	return false;
}

string Board::findKingSquare(bool whosTurn)
{

	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_SIZE; i++)
	{
		for (j = 0; j < COL_SIZE; j++)
		{
			if ((_board[i][j]->getSign() == BLACK_KING && whosTurn) || (_board[i][j]->getSign() == WHITE_KING && !whosTurn))
			{
				string kingSquare = "";
				kingSquare += static_cast<char>('a' + j);
				kingSquare += static_cast<char>('1' + i);
				return kingSquare;
			}
		}
	}
}

void Board::printBoard()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			std::cout << this->_board[i][j]->getSign() << " ";
		}
		std::cout << endl;
	}
	std::cout << endl;
}

string Board::getStart()
{
	return _start;
}
