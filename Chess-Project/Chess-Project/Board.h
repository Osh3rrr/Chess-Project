#pragma once

#include <string>
#include "Piece.h"

#define ROW_SIZE 8
#define COL_SIZE 8

#define WHITE_ROOK 'R'
#define BLACK_ROOK 'r'
#define WHITE_KING 'K'
#define BLACK_KING 'k'
#define BLACK_PAWN 'p'
#define WHITE_PAWN 'P'
#define WHITE_KNIGHT 'N'
#define BLACK_KNIGHT 'n'
#define WHITE_BISHOP 'B'
#define BLACK_BISHOP 'b'
#define BLACK_QUEEN 'q'
#define WHITE_QUEEN 'Q'
#define EMPTY_SPACE '#'

using namespace std;
class Piece;
class Board {
private:
	Piece* _board[ROW_SIZE][COL_SIZE];
	string _start; // the board string at start
public:
	Board();
	~Board();
	void move(string whatMove);
	Piece* getSquare(string square); // Return the piece in the given squre 
	int getRow(char square);
	int getCol(char square);
	bool isPlayerCheckedHimself(bool whosTurn);
	string findKingSquare(bool whosTurn);
	void printBoard();
	string getStart();

};
