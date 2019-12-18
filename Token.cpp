#define TOKEN_CPP

#include "Token.h"

//**********  Static Variables from Token Class **********

Token::UChar Token::LastChar;

ifstream Token::SourceFile;

Token::InputType Token::InputTable [] =			{
												InputUnknown,		// 00
												InputUnknown,		// 01
												InputUnknown,		// 02
												InputUnknown,		// 03
												InputUnknown,		// 04
												InputUnknown,		// 05
												InputUnknown,		// 06
												InputUnknown,		// 07
												InputUnknown,		// 08
												InputSpace,			// 09
												InputSpace,			// 0A
												InputUnknown,		// 0B
												InputUnknown,		// 0C
												InputSpace,			// 0D
												InputUnknown,		// 0E
												InputUnknown,		// 0F
												InputUnknown,		// 10
												InputUnknown,		// 11
												InputUnknown,		// 12
												InputUnknown,		// 13
												InputSpace,			// 14
												InputUnknown,		// 15
												InputUnknown,		// 16
												InputUnknown,		// 17
												InputUnknown,		// 18
												InputUnknown,		// 19
												InputUnknown,		// 1A
												InputUnknown,		// 1B
												InputUnknown,		// 1C
												InputUnknown,		// 1D
												InputUnknown,		// 1E
												InputUnknown,		// 1F
												InputSpace,			// 20
												InputUnknown,		// 21
												InputUnknown,		// 22
												InputUnknown,		// 23
												InputUnknown,		// 24
												InputUnknown,		// 25
												InputUnknown,		// 26
												InputUnknown,		// 27
												InputOpenParen,		// 28
												InputCloseParen,	// 29
												InputAsterisk,		// 2A
												InputPlus,			// 2B
												InputUnknown,		// 2C
												InputMinus,			// 2D
												InputUnknown,		// 2E
												InputSlash,			// 2F
												Input0,				// 30
												Input1,				// 31
												Input2,				// 32
												Input3,				// 33
												Input4,				// 34
												Input5,				// 35
												Input6,				// 36
												Input7,				// 37
												Input8,				// 38
												Input9,				// 39
												InputUnknown,		// 3A
												InputSemiColon,		// 3B
												InputUnknown,		// 3C
												InputUnknown,		// 3D
												InputUnknown,		// 3E
												InputUnknown,		// 3F
												InputUnknown,		// 40
												InputA,				// 41
												InputUnknown,		// 42
												InputUnknown,		// 43
												InputUnknown,		// 44
												InputE,				// 45
												InputUnknown,		// 46
												InputUnknown,		// 47
												InputUnknown,		// 48
												InputUnknown,		// 49
												InputUnknown,		// 4A
												InputUnknown,		// 4B
												InputL,				// 4C
												InputUnknown,		// 4D
												InputUnknown,		// 4E
												InputUnknown,		// 4F
												InputP,				// 50
												InputUnknown,		// 51
												InputUnknown,		// 52
												InputUnknown,		// 53
												InputUnknown,		// 54
												InputU,				// 55
												InputV,				// 56
												InputUnknown,		// 57
												InputX,				// 58
												InputUnknown,		// 59
												InputUnknown,		// 5A
												InputUnknown,		// 5B
												InputUnknown,		// 5C
												InputUnknown,		// 5D
												InputUnknown,		// 5E
												InputUnknown,		// 5F
												InputUnknown,		// 60
												InputA,				// 61
												InputUnknown,		// 62
												InputUnknown,		// 63
												InputUnknown,		// 64
												InputE,				// 65
												InputUnknown,		// 66
												InputUnknown,		// 67
												InputUnknown,		// 68
												InputUnknown,		// 69
												InputUnknown,		// 6A
												InputUnknown,		// 6B
												InputL,				// 6C
												InputUnknown,		// 6D
												InputUnknown,		// 6E
												InputUnknown,		// 6F
												InputP,				// 70
												InputUnknown,		// 71
												InputUnknown,		// 72
												InputUnknown,		// 73
												InputUnknown,		// 74
												InputU,				// 75
												InputV,				// 76
												InputUnknown,		// 77
												InputX,				// 78
												InputUnknown,		// 79
												InputUnknown,		// 7A
												InputUnknown,		// 7B
												InputUnknown,		// 7C
												InputUnknown,		// 7D
												InputUnknown,		// 7E
												InputUnknown,		// 7F
												InputUnknown,		// 80
												InputUnknown,		// 81
												InputUnknown,		// 82
												InputUnknown,		// 83
												InputUnknown,		// 84
												InputUnknown,		// 85
												InputUnknown,		// 86
												InputUnknown,		// 87
												InputUnknown,		// 88
												InputUnknown,		// 89
												InputUnknown,		// 8A
												InputUnknown,		// 8B
												InputUnknown,		// 8C
												InputUnknown,		// 8D
												InputUnknown,		// 8E
												InputUnknown,		// 8F
												InputUnknown,		// 90
												InputUnknown,		// 91
												InputUnknown,		// 92
												InputUnknown,		// 93
												InputUnknown,		// 94
												InputUnknown,		// 95
												InputUnknown,		// 96
												InputUnknown,		// 97
												InputUnknown,		// 98
												InputUnknown,		// 99
												InputUnknown,		// 9A
												InputUnknown,		// 9B
												InputUnknown,		// 9C
												InputUnknown,		// 9D
												InputUnknown,		// 9E
												InputUnknown,		// 9F
												InputUnknown,		// A0
												InputUnknown,		// A1
												InputUnknown,		// A2
												InputUnknown,		// A3
												InputUnknown,		// A4
												InputUnknown,		// A5
												InputUnknown,		// A6
												InputUnknown,		// A7
												InputUnknown,		// A8
												InputUnknown,		// A9
												InputUnknown,		// AA
												InputUnknown,		// AB
												InputUnknown,		// AC
												InputUnknown,		// AD
												InputUnknown,		// AE
												InputUnknown,		// AF
												InputUnknown,		// B0
												InputUnknown,		// B1
												InputUnknown,		// B2
												InputUnknown,		// B3
												InputUnknown,		// B4
												InputUnknown,		// B5
												InputUnknown,		// B6
												InputUnknown,		// B7
												InputUnknown,		// B8
												InputUnknown,		// B9
												InputUnknown,		// BA
												InputUnknown,		// BB
												InputUnknown,		// BC
												InputUnknown,		// BD
												InputUnknown,		// BE
												InputUnknown,		// BF
												InputUnknown,		// C0
												InputUnknown,		// C1
												InputUnknown,		// C2
												InputUnknown,		// C3
												InputUnknown,		// C4
												InputUnknown,		// C5
												InputUnknown,		// C6
												InputUnknown,		// C7
												InputUnknown,		// C8
												InputUnknown,		// C9
												InputUnknown,		// CA
												InputUnknown,		// CB
												InputUnknown,		// CC
												InputUnknown,		// CD
												InputUnknown,		// CE
												InputUnknown,		// CF
												InputUnknown,		// D0
												InputUnknown,		// D1
												InputUnknown,		// D2
												InputUnknown,		// D3
												InputUnknown,		// D4
												InputUnknown,		// D5
												InputUnknown,		// D6
												InputUnknown,		// D7
												InputUnknown,		// D8
												InputUnknown,		// D9
												InputUnknown,		// DA
												InputUnknown,		// DB
												InputUnknown,		// DC
												InputUnknown,		// DD
												InputUnknown,		// DE
												InputUnknown,		// DF
												InputUnknown,		// E0
												InputUnknown,		// E1
												InputUnknown,		// E2
												InputUnknown,		// E3
												InputUnknown,		// E4
												InputUnknown,		// E5
												InputUnknown,		// E6
												InputUnknown,		// E7
												InputUnknown,		// E8
												InputUnknown,		// E9
												InputUnknown,		// EA
												InputUnknown,		// EB
												InputUnknown,		// EC
												InputUnknown,		// ED
												InputUnknown,		// EE
												InputUnknown,		// EF
												InputUnknown,		// F0
												InputUnknown,		// F1
												InputUnknown,		// F2
												InputUnknown,		// F3
												InputUnknown,		// F4
												InputUnknown,		// F5
												InputUnknown,		// F6
												InputUnknown,		// F7
												InputUnknown,		// F8
												InputUnknown,		// F9
												InputUnknown,		// FA
												InputUnknown,		// FB
												InputUnknown,		// FC
												InputUnknown,		// FD
												InputUnknown,		// FE
												EndOfFile			// FF
												};

Token::TokenFunc Token::StateFunction [] =		{
												NotYetWritten,			//	0
												GotE,					//  1
												GotV,					//  2
												GotEV,					//	3
												GotEVA,					//	4
												GotEVAL,				//	5
												GotEndOfFile,			//	6
												GotUnexpectedEOF,		//	7
												StartedTokenWithSpace,	//	8
												GotInvalidInput,		//  9
												GotVA,					//	10
												GotVAL,					//	11
												GotVALU,				//	12
												GotVALUE,				//	13
												GotEX,					//	14
												GotEXP,					//	15
												GotVDigit,				//	16
												GotVDigitDigit,			//	17
												GotDigit,				//	18
												GotAnotherDigit,		//	19
												GotNonDigit,			//	20
												GotUnknownInput,		//	21
												GotPlus,				//	22
												GotMinus,				//	23
												GotAsterisk,			//	24
												GotSlash,				//	25
												GotOpenParen,			//	26
												GotCloseParen,			//	27
												GotSemiColon			//	28
												};

Token::UChar Token::StateTable [NumInputs] [NumStates] =	{
						//							StartGettingToken	AfterE	AfterV	AfterEV	AfterEVA AfterVA AfterVAL AfterVALU AfterEX AfterVDigit AfterDigit
						/*	InputUnknown	*/	{			9,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputA			*/	{			9,				9,		10,		4,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputE			*/	{			1,				9,		9,		9,		9,		9,		9,		13,			9,		9,			20,		},
						/*	InputL			*/	{			9,				9,		9,		9,		5,		11,		9,		9,			9,		9,			20,		},
						/*	InputP			*/	{			9,				9,		9,		9,		9,		9,		9,		9,			15,		9,			20,		},
						/*	InputU			*/	{			9,				9,		9,		9,		9,		9,		12,		9,			9,		9,			20,		},
						/*	InputV			*/	{			2,				3,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputX			*/	{			9,				14,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	Input0			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input1			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input2			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input3			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input4			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input5			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input6			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input7			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input8			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	Input9			*/	{			18,				9,		16,		9,		9,		9,		9,		9,			9,		17,			19,		},
						/*	InputPlus		*/	{			22,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputMinus		*/	{			23,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputAsterisk	*/	{			24,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputSlash		*/	{			25,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputOpenParen	*/	{			26,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputCloseParen	*/	{			27,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputSemiColon	*/	{			28,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	InputSpace		*/	{			8,				9,		9,		9,		9,		9,		9,		9,			9,		9,			20,		},
						/*	EndOfFile		*/	{			6,				7,		7,		7,		7,		7,		7,		7,			7,		7,			20,		},
												};

Variable Token::VariableArray [NumVariables];

//********** Methods from Token Class **********

Token & Token::Build ()
	{
	if (SourceFile.is_open ())
			{
			TokenState CurrentState (StartGettingToken);
			SetType (UnknownToken);
			do	{
				CurrentState = StateFunction [StateTable [GetInputChar ()] [CurrentState] ] (*this);
				} while (CurrentState != TokenComplete);
			return *this;
			}
		else
			throw TokenFileNotOpen;
	}

Token::TokenState Token::NotYetWritten (Token &)
	{
	cout << "You called a method which has not yet been implemented" << endl;
	return TokenComplete;
	}

Token::TokenState Token::GotE (Token &)
	{
	return AfterE;
	}

Token::TokenState Token::GotV (Token &)
	{
	return AfterV;
	}

Token::TokenState Token::GotEV (Token &)
	{
	return AfterEV;
	}

Token::TokenState Token::GotEVA (Token &)
	{
	return AfterEVA;
	}

Token::TokenState Token::GotEVAL (Token & T)
	{
	T.SetType (KeywordEvalToken);
	return TokenComplete;
	}

Token::TokenState Token::GotEndOfFile (Token & T)
	{
	T.SetType (EndOfInputToken);
	return TokenComplete;
	}

Token::TokenState Token::GotEX (Token &)
	{
	return AfterEX;
	}

Token::TokenState Token::GotEXP (Token & T)
	{
	T.SetType (KeywordExpToken);
	return TokenComplete;
	}

Token::TokenState Token::GotUnexpectedEOF (Token & T)
	{
	cout << "Got Unexpected EOF" << endl;
	T.SetType (EndOfInputToken);
	return TokenComplete;
	}

Token::TokenState Token::GotVA (Token &)
	{
	return AfterVA;
	}

Token::TokenState Token::GotVAL (Token &)
	{
	return AfterVAL;
	}

Token::TokenState Token::GotVALU (Token &)
	{
	return AfterVALU;
	}

Token::TokenState Token::GotVALUE (Token & T)
	{
	T.SetType(KeywordValueToken);
	return TokenComplete;
	}

Token::TokenState Token::GotVDigit (Token & T)
	{
	T.SetWhich(T.LastChar - '0');
	return AfterVDigit;
	}

Token::TokenState Token::GotVDigitDigit (Token & T)
	{
	T.SetWhich((T.GetWhich() * 10) + (T.LastChar - '0'));
	T.SetType(VariableToken);
	return TokenComplete;
	}

Token::TokenState Token::GotDigit (Token & T)
	{
	T.SetType(ConstantToken);
	T.SetValue(T.LastChar - '0');
	return AfterDigit;
	}

Token::TokenState Token::GotAnotherDigit (Token & T)
	{
	T.SetValue((T.GetValue() * 10) + (T.LastChar - '0'));
	return AfterDigit;
	}

Token::TokenState Token::GotNonDigit (Token & T)
	{
	T.PutBackLastChar();
	return TokenComplete;
	}

Token::TokenState Token::GotPlus (Token & T)
	{
	T.SetType(OperatorPlusToken);
	return TokenComplete;
	}

Token::TokenState Token::GotMinus (Token & T)
	{
	T.SetType(OperatorMinusToken);
	return TokenComplete;
	}

Token::TokenState Token::GotAsterisk (Token & T)
	{
	T.SetType(OperatorAsteriskToken);
	return TokenComplete;
	}

Token::TokenState Token::GotSlash (Token & T)
	{
	T.SetType(OperatorSlashToken);
	return TokenComplete;
	}

Token::TokenState Token::GotOpenParen (Token & T)
	{
	T.SetType(SymbolOpenParenToken);
	return TokenComplete;
	}

Token::TokenState Token::GotCloseParen (Token & T)
	{
	T.SetType(SymbolCloseParenToken);
	return TokenComplete;
	}

Token::TokenState Token::GotSemiColon (Token & T)
	{
	T.SetType(SymbolSemiColonToken);
	return TokenComplete;
	}

Token::TokenState Token::StartedTokenWithSpace (Token &)
	{
	return StartGettingToken;
	}

Token::TokenState Token::GotUnknownInput (Token & T)
	{
	cout << "Got unexpected input" << endl;
	T.SetType (UnknownToken);
	return TokenComplete;
	}

Token::TokenState Token::GotInvalidInput (Token & T)
	{
	cout << "Got invalid input" << endl;
	T.SetType (UnknownToken);
	return TokenComplete;
	}