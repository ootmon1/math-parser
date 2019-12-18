#include "Statement.h"

// static variables from Statement class
MathTree Statement::MT;

Token Statement::LastToken;

Statement::StatementFunc Statement::StateFunction [] =	{
														NotYetWritten,			//	0
														GotBadInput,			//  1
														GotEOF,					//  2
														GotUnexpEOF,			//	3
														GotSCAtStart,			//	4
														GotEval,				//	5
														GotEvalSC,				//	6
														GotValue,				//	7
														GotValueVar,			//	8
														GotValueVarConst,		//  9
														GotValueVarPlus,		//	10
														GotValueVarMinus,		//	11
														GotExp,					//	12
														GotBadExpression,		//	13
														GotSkippedToken,		//	14
														GotSCWhileSkipping,		//	15
														GotOperand,				//	16
														GotUnaryOp,				//	17
														GotOpenParen,			//	18
														GotCloseParen,			//	19
														GotBinaryPlusMinus,		//	20
														GotSCAfterOperand,		//	21
														GotStatement,			//	22
														GotMultiplyDivide,		//	23
														GotSCAfterOp,			//	24
														GotBadSC				//	25
														};

Statement::UChar Statement::StateTable[Token::NumTokens][NumStates] =	{
							//	StartStatement AfterEval AfterValue	AfterValueVar AfterValueVarConst AfterValueVarSign AfterExp	SkipToSemiCol AfterOperand AfterUnaryOp AfterOperator
	/* EndOfInputToken		 */  {	2,			3,			3,			3,			3,					3,				3,			3,			3,			3,				3,			},
	/* UnknownToken			 */	 {	1,			1,			1,			1,			1,					1,				13,			14,			13,			13,				13,			},
	/* VariableToken		 */	 {	1,			1,			8,			1,			1,					1,				16,			14,			13,			16,				16,			},
	/* ConstantToken		 */	 {	1,			1,			1,			9,			1,					9,				16,			14,			13,			16,				16,			},
	/* KeywordEvalToken		 */	 {	5,			1,			1,			1,			1,					1,				13,			14,			13,			13,				13,			},
	/* KeywordExpToken		 */	 {	12,			1,			1,			1,			1,					1,				13,			14,			13,			13,				13,			},
	/* KeywordValueToken	 */	 {	7,			1,			1,			1,			1,					1,				13,			14,			13,			13,				13,			},
	/* OperatorPlusToken	 */	 {	1,			1,			1,			10,			1,					1,				17,			14,			20,			13,				17,			},
	/* OperatorMinusToken	 */	 {	1,			1,			1,			11,			1,					1,				17,			14,			20,			13,				17,			},
	/* OperatorAsteriskToken */	 {	1,			1,			1,			1,			1,					1,				13,			14,			23,			13,				13,			},
	/* OperatorSlashToken	 */	 {	1,			1,			1,			1,			1,					1,				13,			14,			23,			13,				13,			},
	/* SymbolOpenParenToken	 */	 {	1,			1,			1,			1,			1,					1,				18,			14,			13,			18,				18,			},
	/* SymbolCloseParenToken */	 {	1,			1,			1,			1,			1,					1,				13,			14,			19,			13,				13,			},
	/* SymbolSemiColonToken	 */	 {	4,			6,			25,			25,			22,					25,				22,			22,			21,			24,				24,			},
																		};

// methods from Statement class
Statement & Statement::Build ()
	{
	Token	Toke;
	StatementState CurrentState	(StartStatement);
	
	try {
		do	{
			CurrentState = StateFunction [StateTable [Toke.Build().GetType()][CurrentState]] (*this, Toke);
			} while (CurrentState != StatementComplete);
		}
	catch (Variable::Exception e)
		{
		switch (e)
			{
			case Variable::Exception::VariableNotDefinedException:
				cout << "Error: variable has not been defined" << endl;
				break;
			default:
				cout << "Internal Error 202" << endl;
			}
		}
	return *this;
	}

Statement::StatementState Statement::NotYetWritten(Statement &, Token &)
	{
	cout << "You called a method which has not yet been implemented" << endl;
	return StartStatement;
	}

Statement::StatementState Statement::GotBadInput (Statement & S, Token &)
	{
	cout << "Error: invalid statement" << endl;
	return SkipToSemiColon;
	}

Statement::StatementState Statement::GotBadSC (Statement & S, Token &)
	{
	cout << "Error: invalid statement" << endl;
	return StartStatement;
	}

Statement::StatementState Statement::GotSCAtStart(Statement &, Token &)
	{
	cout << "Empty statement" << endl;
	return StartStatement;
	}

Statement::StatementState Statement::GotEval (Statement &, Token &)
	{
	return AfterEval;
	}

Statement::StatementState Statement::GotStatement (Statement &, Token &)
	{
	return StartStatement;
	}

Statement::StatementState Statement::GotEvalSC (Statement & S, Token &)
	{
	try {
		cout << "Result is " << S.MT.Evaluate() << endl;
		}
	catch (MathTree::ResultCode e)
		{
		switch (e)
			{
			case MathTree::ResultCode::DivideByZero:
				cout << "Error: division by zero is not defined" << endl;
				break;
			default:
				cout << "Internal Error 202" << endl;
			}
		}
	return StartStatement;
	}

Statement::StatementState Statement::GotEOF (Statement & S, Token &)
	{
	cout << "End of input" << endl;
	Token::CloseFile();
	S.MT.Delete();
	exit(0);
	}

Statement::StatementState Statement::GotUnexpEOF (Statement & S, Token & T)
	{
	cout << "Got unexpected EOF" << endl;
	return GotEOF(S, T);
	}

Statement::StatementState Statement::GotValue (Statement & S, Token &)
	{
	S.Sign = true;
	return AfterValue;
	}

Statement::StatementState Statement::GotValueVar (Statement & S, Token & T)
	{
	S.LastToken = T;
	return AfterValueVar;
	}

Statement::StatementState Statement::GotValueVarConst (Statement & S, Token & T)
	{
	S.LastToken.SetValue(S.Sign ? T.GetValue() : -T.GetValue());
	return AfterValueVarConst;
	}

Statement::StatementState Statement::GotValueVarPlus (Statement & S, Token &)
	{
	S.Sign = true;
	return AfterValueVarSign;
	}

Statement::StatementState Statement::GotValueVarMinus (Statement & S, Token &)
	{
	S.Sign = false;
	return AfterValueVarSign;
	}

Statement::StatementState Statement::GotExp (Statement & S, Token & T)
	{
	S.NumOpenParen = 0;
	S.MT.Delete();
	return AfterExp;
	}

Statement::StatementState Statement::GotBadExpression (Statement & S, Token &)
	{
	S.MT.Delete();
	cout << "Error: invalid expression" << endl;
	return SkipToSemiColon;
	}

Statement::StatementState Statement::GotSCAfterOp (Statement & S, Token &)
	{
	S.MT.Delete();
	cout << "Error: invalid expression" << endl;
	return StartStatement;
	}

Statement::StatementState Statement::GotSkippedToken (Statement &, Token &)
	{
	return SkipToSemiColon;
	}

Statement::StatementState Statement::GotSCWhileSkipping (Statement &, Token &)	// this function was replaced by GotStatement
	{
	return StartStatement;
	}

Statement::StatementState Statement::GotOperand (Statement & S, Token & T)
	{
	S.MT.InsertOperand(T);
	return AfterOperand;
	}

Statement::StatementState Statement::GotUnaryOp (Statement & S, Token & T)
	{
	T.SetPrecedence(static_cast <Operator::Precedence> ((S.NumOpenParen * Operator::ParenthesesPrecedence) + Operator::UnaryPlusMinusPrecedence));
	S.MT.InsertUnaryOperator(T);
	return AfterUnaryOp;
	}

Statement::StatementState Statement::GotBinaryPlusMinus (Statement & S, Token & T)
	{
	T.SetPrecedence(static_cast <Operator::Precedence> ((S.NumOpenParen * Operator::ParenthesesPrecedence) + Operator::BinaryPlusMinusPrecedence));
	S.MT.InsertBinaryOperator(T);
	return AfterOperator;
	}

Statement::StatementState Statement::GotMultiplyDivide (Statement & S, Token & T)
	{
	T.SetPrecedence(static_cast <Operator::Precedence> ((S.NumOpenParen * Operator::ParenthesesPrecedence) + Operator::MultiplyDividePrecedence));
	S.MT.InsertBinaryOperator(T);
	return AfterOperator;
	}

Statement::StatementState Statement::GotOpenParen (Statement & S, Token &)
	{
	S.NumOpenParen++;
	return AfterOperator;
	}

Statement::StatementState Statement::GotCloseParen (Statement & S, Token &)
	{
	if (S.NumOpenParen > 0)
			{
			S.NumOpenParen--;
			return AfterOperand;
			}
		else
			{
			cout << "Error: unmatched closed parentheses" << endl;
			S.NumOpenParen = 0;
			S.MT.Delete();
			return SkipToSemiColon;
			}
	}

Statement::StatementState Statement::GotSCAfterOperand (Statement & S, Token &)
	{
	if (S.NumOpenParen == 0)
			{
			return StartStatement;
			}
		else
			{
			cout << "Error: unmatched open parentheses" << endl;
			S.NumOpenParen = 0;
			S.MT.Delete();
			return StartStatement;
			}
	}