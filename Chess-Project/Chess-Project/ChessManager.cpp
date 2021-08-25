#include "ChessManager.h"
#include <string>
#include "graphicBoard.h"

ChessManager::ChessManager()
{
}

ChessManager::~ChessManager()
{
}

void ChessManager::game()
{
	string movement = "", moveBack = "", temp = "", src = "", dst = "";
	Board* gameBoard = new Board();
	Turn* playerTurn = new Turn();
	graphicBoard* gameGraphicBoard = new graphicBoard();

	gameGraphicBoard->initGrpahicBoard(gameBoard->getStart());

	while (true)
	{
		gameBoard->printBoard();

		movement = gameGraphicBoard->getMovmentFromGraphicBoard();

		src = string() + movement[0] + movement[1];
		dst = string() + movement[2] + movement[3];

		temp = string() + movement[2] + movement[3];
		moveBack = string() + dst + src;
		// moveBack += temp;

		if (gameBoard->getSquare(src)->checkIfMoveIsValid(gameBoard, movement, playerTurn->getPlayerTurn())[0] == '0')
		{
			gameBoard->move(movement);

			if (gameBoard->isPlayerCheckedHimself(playerTurn->getPlayerTurn()))
			{
				gameBoard->printBoard();
				cout << "BAD MOVE! CHECK!" << endl;
				cout << moveBack << endl;
				gameBoard->move(moveBack);
				gameBoard->printBoard();
				gameGraphicBoard->sendProtocolCodes("4");
			}

			else
			{
				if (gameBoard->isPlayerCheckedHimself(!(playerTurn->getPlayerTurn())))
				{
					gameGraphicBoard->sendProtocolCodes("1"); // send to graphic that is correct move and check.
				}
				else
				{
					gameGraphicBoard->sendProtocolCodes("0"); // send to graphic that is correct move.
				}
				cout << "MOVE!" << endl;
				playerTurn->changeTurn();
			}
		}

		else
		{
			cout << "BAD MOVE" << endl;
			gameGraphicBoard->sendProtocolCodes(gameBoard->getSquare(src)->checkIfMoveIsValid(gameBoard, movement, playerTurn->getPlayerTurn()));
		}
	}


	delete gameBoard;
	delete playerTurn;
	delete gameGraphicBoard;
}
