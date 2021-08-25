#include "graphicBoard.h"

#define BOARD_LEN 66

void graphicBoard::initGrpahicBoard(string code)
{
	int i = 0;
	Pipe p;
	string ans;
	bool isConnect = p.connect();
	char msgToGrpahics[1024];
	char codeCharArray[BOARD_LEN] = { 0 };

	srand(time_t(NULL));

	while (!isConnect) // if the connection failed.
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	// We should convert the code string to char* to use strcpy function:
	
	for (i = 0; i < code.length(); i++)
	{
		codeCharArray[i] = code[i];
	}

	strcpy_s(msgToGrpahics, codeCharArray);

	p.sendMessageToGraphics(msgToGrpahics); // sending the message;

	this->p = p;
}

string graphicBoard::getMovmentFromGraphicBoard()
{
	return p.getMessageFromGraphics();
}

void graphicBoard::sendProtocolCodes(string code)
{
	char msgToGraphics[2] = { code[0], NULL };
	p.sendMessageToGraphics(msgToGraphics);
}

