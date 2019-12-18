//********************************************************************************
//
//	DESCRIPTION:	Semester Project - An application that parses input from a
//						file into statements that are used to perform calculations
//	AUTHOR:			John Dixon
//	CLASS:			COSC 2336.S01
//	DATE:			12/7/2017
//
//********************************************************************************

#include "Statement.h"

void main (int argc, char * argv [])
	{
	if (argc < 2)
			{
			cout << "You need to place the file name on the command line" << endl;
			exit (0);
			}
		else;

	// the following three lines are just to show what was entered on the command line
	cout << "Argv [0] is " << argv [0] << endl;
	cout << "Argv [1] is " << argv [1] << endl;

	WCS_String	FileName(argv [1]);
	Statement	S;

	Token::OpenFile(FileName);

	try {
		do	{
			S.Build();
			} while (true);
		}
	catch (Token::Exception e)
		{
		switch (e)
			{
			case Token::Exception::TokenFileNotOpen:
				cout << "Input file has not been opened" << endl;
				break;
			default:
				cout << "Internal Error 303" << endl;
			}
		}
	}