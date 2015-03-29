/*
 * Rook.cpp
 *
 *  Created on: 24-Nov-2008
 *      Author: Vile Lasagna
 */


#include "Rook.h"


Rook::Rook (Pos p)
{
	piece_ID = pieceID::pieceID(true);
	at = p;
	pointvalue = 5;
}

Rook::Rook(Pos p, bool c)
{
	piece_ID = pieceID::pieceID(c, pieceID::Rook);
	at = p;
	pointvalue = 5;
}

const bool Rook::canGo(Pos& to, BD& vec)
{
	int difX = to.getX() - at.getX();
	int difY = to.getY() - at.getY();
	if ((difX !=0)&&(difY != 0))
	{
		return false;
	}
	piece* p = (piece*) (vec[to.getX()][to.getY()].getPiece());
	if(p)
	{
		if (p->getColour() == this->getColour())
		{
			return false;
		}
	}
	if (difX == 0)
	{
		if(difY > 0)
		{
			for(int i = (at.getY()+1); i < to.getY(); i++)
			{
				if(vec[at.getX()][i].getPiece())
				{
					return false;
				}
			}

		}
		else
		{
			for(int i = (at.getY()-1); i > to.getY(); i--)
			{
				if(vec[at.getX()][i].getPiece())
				{
					return false;
				}
			}
		}
	}
	else
	{
		if (difX > 0)
		{
			for(int i = (at.getX()+1); i < to.getX(); i++)
			{
				if(vec[i][at.getY()].getPiece())
				{
					return false;
				}
			}
		}
		else
		{
			for(int i = (at.getX()-1); i > to.getX(); i--)
			{
				if(vec[i][at.getY()].getPiece())
				{
					return false;
				}
			}
		}
	}
	return true;
}

const bool Rook::canMove (Pos& to, BD& vec)
{
	if(canGo(to, vec))
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

const std::vector<Pos> Rook::getMoves(BD& vec)
{
	std::vector<Pos> moves;
	int x;
	int y;
	if(at.getY()!= 8)
	{
		y = at.getY();
		while (true)
		{
			y++;
			moves.push_back(Pos(at.getX(), y));
			if (y == 8)
			{
				break;
			}
		}
	}
	if (at.getY() != 1)
	{
		y = at.getY();
		while(true)
		{
			y--;
			moves.push_back(Pos(at.getX(),y));
			if(y == 1)
			{
				break;
			}
		}
	}
	if (at.getX() != 8)
	{
		x = at.getX();
		while (true)
		{
			x++;
			moves.push_back(Pos(x, at.getY()));
			if (x == 8)
			{
				break;
			}
		}
	}
	if (at.getX() != 1)
	{
		x = at.getX();
		while(true)
		{
			x--;
			moves.push_back(Pos(x, at.getY()));
			if (x == 1)
			{
				break;
			}
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
