#pragma once

#include <string>
#include <iostream>
#include "Pipe.h"
#include <thread>

using namespace std;

class graphicBoard
{
	private:
		Pipe p;

	public:
		void initGrpahicBoard(string code);
		string getMovmentFromGraphicBoard();
		void sendProtocolCodes(string code);
};
