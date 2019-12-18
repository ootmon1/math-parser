#include <stdlib.h>

#include "MathTree.h"

MathTree::Node::Node (const Token & T): Toke (T)
	{
	}

MathTree::Node::~Node()
	{
	//cout << "Node deleted" << endl;
	}

MathTree::MathTree ()
	{
	}

MathTree::~MathTree ()
	{
	Delete ();
	}

void MathTree::Delete ()
	{
	if (pRoot)
			{
			WCS_Pointer <Node>		Ptr (GetLeftMostOperator (pRoot));

			if (pLastOperator)
					pLastOperator.SetToNull();
				else;

			while (Ptr)
				if (!(*Ptr).LeftSideDone)
						{
						(*Ptr).pLeft.SetToNull();
						(*Ptr).LeftSideDone = true;
						if ((*Ptr).pRight)
								Ptr = GetLeftMostOperator((*Ptr).pRight);
							else;
						}
					else
						{
						(*Ptr).pRight.SetToNull();
						Ptr = (*Ptr).pParent;
						}
			pRoot.SetToNull();
			}
	}

Variable::ValueType MathTree::Evaluate ()
	{
	if (pRoot)
			{
			WCS_Pointer <Node>		Ptr (GetLeftMostOperator (pRoot));	// Ptr could end up as NULL if tree is only a constant or variable

			while (Ptr)
				if (!(*Ptr).LeftSideDone)
						{
						(*Ptr).Toke.SetValue ((*(*Ptr).pLeft).Toke.GetValue ());
						(*Ptr).LeftSideDone = true;
						Ptr					= GetLeftMostOperator ((*Ptr).pRight);
						}
					else
						{
						switch ((*Ptr).Toke.GetType ())
							{
							case Token::OperatorPlusToken:
											(*Ptr).Toke.SetValue ((*Ptr).Toke.GetValue () + (*(*Ptr).pRight).Toke.GetValue ());
											break;
							case Token::OperatorMinusToken:
											(*Ptr).Toke.SetValue ((*Ptr).Toke.GetValue () - (*(*Ptr).pRight).Toke.GetValue ());
											break;
							case Token::OperatorAsteriskToken:
											(*Ptr).Toke.SetValue ((*Ptr).Toke.GetValue () * (*(*Ptr).pRight).Toke.GetValue ());
											break;
							case Token::OperatorSlashToken:
											if ((*(*Ptr).pRight).Toke.GetValue () != 0)
													(*Ptr).Toke.SetValue ((*Ptr).Toke.GetValue () / (*(*Ptr).pRight).Toke.GetValue ());
												else
													throw DivideByZero;
											break;
							default:
											cout << "Internal error 101" << endl;
											exit (0);
							}
						Ptr	= (*Ptr).pParent;
						}
			return (*pRoot).Toke.GetValue ();
			}
		else
			return 0;
	}

WCS_Pointer <MathTree::Node> & MathTree::GetLeftMostOperator (const WCS_Pointer <Node> & pStart)
	{
	WCS_Pointer <Node> Ptr (pStart);

	while ((*Ptr).pLeft)
		{
		(*Ptr).LeftSideDone		= false;
		Ptr						= (*Ptr).pLeft;
		}
	return (*Ptr).pParent;		// if tree only has a constant or variable, we will return NULL
	}

MathTree::ResultCode MathTree::InsertBinaryOperator (const Token & T)
	{
	WCS_Pointer <Node>	pNewOperator	(new Node (T));

	while (pLastOperator && ((*pLastOperator).Toke.GetPrecedence () >= (*pNewOperator).Toke.GetPrecedence ()))
		pLastOperator = (*pLastOperator).pParent;
	if (!pLastOperator)		// we backed all the way out of the tree
			{
			(*pNewOperator).pLeft	= pRoot;
			(*pRoot).pParent		= pNewOperator;
			pRoot					= pNewOperator;
			}
		else
			{		// we are adding a new operator into the middle of the tree
			(*pNewOperator).pLeft				= (*pLastOperator).pRight;
			(*pNewOperator).pParent				= pLastOperator;
			(*(*pLastOperator).pRight).pParent	= pNewOperator;
			(*pLastOperator).pRight				= pNewOperator;
			}
	pLastOperator	= pNewOperator;
	return OK;
	}

MathTree::ResultCode MathTree::InsertOperand (const Token & T)
	{
	WCS_Pointer <Node>	pTemp (new Node (T));

	if (!pRoot)
			pRoot = pTemp;
		else
			{
			(*pLastOperator).pRight		= pTemp;
			(*pTemp).pParent			= pLastOperator;
			}
	return OK;
	}

MathTree::ResultCode MathTree::InsertUnaryOperator (const Token & T)
	{
	Token Temp (Token::ConstantToken, 0);

	InsertOperand (Temp);
	return InsertBinaryOperator (T);
	}