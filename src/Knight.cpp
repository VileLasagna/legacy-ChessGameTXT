/*
 * Knight.cpp
 *
 *  Created on: 24-Nov-2008
 *      Author: Vile Lasagna
 */

#include "Knight.h"


Knight::Knight(Pos p)
{
	piece_ID = pieceID::pieceID(true);
	pointvalue = 3;
	at = p;
}
Knight::Knight(Pos p, bool c)
{
	piece_ID = pieceID::pieceID(c, pieceID::Knight);
	at = p;
	pointvalue = 3;
}

const bool Knight::canGo(Pos& to, BD& vec)
{
	int difX = to.getX() - at.getX();
	int difY = to.getY() - at.getY();

	if ((difX != 2) && (difX != (-2)) && (difY != 2) && (difY != (-2)))
	{
		return false;
	}
	if ((difX != 1) && (difX != (-1)) && (difY != 1) && (difY != (-1)))
	{
		return false;
	}

	if (((difX == 2) || (difX == (-2))) && ((difY == 2) || (difY == (-2))))
	{
		return false;
	}
	if (((difX == 1) || (difX == (-1))) && ((difY == 1) || (difY == (-1))))
	{
		return false;
	}
	
	if ((to.getX() > 8) || (to.getX() < 1) || (to.getY() > 8) || (to.getY() < 1))
	{
		return false;
	}
	piece* p = (piece*) vec[to.getX()][to.getY()].getPiece();
	if (p)
	{
		if ((p->getColour()) == (this->getColour()))
		{
			return false;
		}
	}
	return true;
}

const bool Knight::canMove(Pos& to, BD& vec)
{
	if (canGo(to, vec))
	{
		BD testBoard = Square::BDClone(vec);
		Pos op = at;
		setPos(to,testBoard);
		if(!getCheck(testBoard))
		{
			at = op;
			return true;
		}
		else
		{
			at = op;
			return false;
		}
	}
	else
	{
		return false;
	}
}

const std::vector<Pos> Knight::getMoves(BD& vec)
{
	std::vector<Pos> moves;
	int x = at.getX();
	int y = at.getY();
	if (x < 7)
	{
		if (y < 8)
		{
			moves.push_back(Pos((x+2),(y+1)));
		}
		if (y > 1)
		{
			moves.push_back(Pos((x+2),(y-1)));
		}
	}
	if (x > 2)
	{
		if (y < 8)
		{
			moves.push_back(Pos((x-2),(y+1)));
		}
		if (y > 1)
		{
			moves.push_back(Pos((x-2),(y-1)));
		}
	}
	if (y < 7)
	{
		if (x < 8)
		{
			moves.push_back(Pos((x+1),(y+2)));
		}
		if (x > 1)
		{
			moves.push_back(Pos((x-1),(y+2)));
		}
	}
	if (y > 2)
	{
		if (x < 8)
		{
			moves.push_back(Pos((x+1),(y-2)));
		}
		if (x > 1)
		{
			moves.push_back(Pos((x-1),(y-2)));
		}
	}
	for (int i = (moves.size()-1); i >= 0; i--)
	{
		if (!canMove(moves[i], vec))
		{
			moves.erase(moves.begin()+i);
		}
	}
	return moves;
}
