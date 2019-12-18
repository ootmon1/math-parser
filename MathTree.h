#ifndef MATH_TREE_H
#define MATH_TREE_H

#include <WCS_Pointer.h>

#include "Token.h"

class MathTree
	{
	private:
		struct Node: public RefCount
			{
			WCS_Pointer <Node>		pLeft;
			WCS_Pointer <Node>		pRight;
			WCS_Pointer <Node>		pParent;
			bool					LeftSideDone;
			Token					Toke;

			Node (const Token &);
			~Node();
			};
	public:
		enum	ResultCode {OK, DivideByZero};
								MathTree				();
								~MathTree				();
		void					Delete					();
		Variable::ValueType		Evaluate				();
		ResultCode				InsertBinaryOperator	(const Token &);
		ResultCode				InsertOperand			(const Token &);
		ResultCode				InsertUnaryOperator		(const Token &);
	private:
		WCS_Pointer <Node> &	GetLeftMostOperator		(const WCS_Pointer <Node> &);
								MathTree				(const MathTree &);
		MathTree &				operator =				(const MathTree &);

		WCS_Pointer <Node>		pRoot;
		WCS_Pointer <Node>		pLastOperator;
	};

#endif
