#ifndef STATEMENT_H
#define	STATEMENT_H

#include "MathTree.h"

class Statement
	{
	public:
		// enums
		enum		StatementType	{
									UnknownStatement,
									EvalStatement,
									ValueStatement,
									ExpStatement,

									NumStatements
									};

		// typedefs
		typedef unsigned char		UChar;
		typedef unsigned int		UInt;

		// functions
									Statement			();
									~Statement			();
					Statement &		Build				();
					StatementType	GetType				();
					void			SetType				(StatementType);

	private:
		// enums
		enum		StatementState	{
									StatementComplete = -1,
									StartStatement,
									AfterEval,
									AfterValue,
									AfterValueVar,
									AfterValueVarConst,
									AfterValueVarSign,
									AfterExp,
									SkipToSemiColon,
									AfterOperand,
									AfterUnaryOp,
									AfterOperator,

									NumStates
									};

		// typedefs
		typedef	int					State;
		typedef StatementState		(*StatementFunc)	(Statement &, Token &);

		// functions
		explicit					Statement			(const Statement &);
					Statement &		operator =			(const Statement &);

		static		StatementState	NotYetWritten		(Statement &, Token &);
		static		StatementState	GotBadInput			(Statement &, Token &);
		static		StatementState	GotEOF				(Statement &, Token &);
		static		StatementState	GotUnexpEOF			(Statement &, Token &);
		static		StatementState	GotSCAtStart		(Statement &, Token &);
		static		StatementState	GotEval				(Statement &, Token &);
		static		StatementState	GotEvalSC			(Statement &, Token &);
		static		StatementState	GotValue			(Statement &, Token &);
		static		StatementState	GotValueVar			(Statement &, Token &);
		static		StatementState	GotValueVarConst	(Statement &, Token &);
		static		StatementState	GotValueVarPlus		(Statement &, Token &);
		static		StatementState	GotValueVarMinus	(Statement &, Token &);
		static		StatementState	GotExp				(Statement &, Token &);
		static		StatementState	GotBadExpression	(Statement &, Token &);
		static		StatementState	GotSkippedToken		(Statement &, Token &);
		static		StatementState	GotSCWhileSkipping	(Statement &, Token &);
		static		StatementState	GotOperand			(Statement &, Token &);
		static		StatementState	GotUnaryOp			(Statement &, Token &);
		static		StatementState	GotOpenParen		(Statement &, Token &);
		static		StatementState	GotCloseParen		(Statement &, Token &);
		static		StatementState	GotBinaryPlusMinus	(Statement &, Token &);
		static		StatementState	GotSCAfterOperand	(Statement &, Token &);
		static		StatementState	GotStatement		(Statement &, Token &);
		static		StatementState	GotMultiplyDivide	(Statement &, Token &);
		static		StatementState	GotSCAfterOp		(Statement &, Token &);
		static		StatementState	GotBadSC			(Statement &, Token &);

		// data
		static		MathTree		MT;
		static		StatementFunc	StateFunction	[];
		static		UChar			StateTable		[Token::NumTokens][NumStates];
		static		Token			LastToken;
		
					bool			Sign;
					UInt			NumOpenParen;
					StatementType	Type;				
	};

inline Statement::Statement () : Type (UnknownStatement), Sign (true)
	{
	}

inline Statement::~Statement ()
	{
	}

inline Statement::StatementType Statement::GetType ()
	{
	return Type;
	}

inline void Statement::SetType (StatementType T)
	{
	Type = T;
	}

#endif