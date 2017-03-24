/*
 * piece.cpp
 *
 *  Created on: 27-Oct-2008
 *      Author: Vile Lasagna
 */
#include "piece.h"


void piece::kill()
{

	//throw deadPieceEvent(this);

}

Pos piece::getPos()
{
	return at;
}
piece::piece()
{
	firstMove = true;
}

pieceID::Type piece::getType() const
{
	return piece_ID.getType();
}

void piece::clearPassant (BD& vec)
{
	Pos p(1,1);
	while (!p.endboard())
	{
		vec[p.getX()][p.getY()].setPassant(0);
		p++;
	}
}

bool piece::move(Pos to, BD& vec )
{
	if (canMove(to, vec))
	{
		Pos from = at;
		int x = to.getX(); int y = to.getY();
		piece* id = ((piece*) vec[x][y].getPiece());

		at = to;
		vec[x][y]. setID(this);
		vec[from.getX()][from.getY()].setID(0);
		//if (id)
		//{
		//	id->kill();
		//}
		// And so captured pieces become lost in time...(not QUITE, but almost)
		if (firstMove)
		{
			firstMove = false;
		}
		clearPassant(vec);
		return true;
	}
	return false;
}

bool piece::first() const
{
	return firstMove;
}

pieceID piece::getID() const
{
	return piece_ID;
}

bool piece::getColour() const
{
	return piece_ID.getColour();
}

bool piece::getCheck(BD& vec) const
{
	Pos p(1,1);
	piece* myLiege = 0;
	while (true)//where's the king, in the first place?
	{
		myLiege = ((piece*) ((vec[p.getX()][p.getY()]).getPiece()));
		if ( (myLiege) && ((myLiege->getColour()==this->getColour() )&& (myLiege->getType()== pieceID::King)))
		{
			break;//Aha! here he is!
		}
		if (p.endboard())
		{
			/*
			 * If there's no king to be found in the board something is
			 * very VERY wrong.
			 */
			if (this->getColour())
			{
				throw FatalErrorException("No White King Found!!");
			}
			else
			{
				throw FatalErrorException("No Black King Found!!");
			}
		}
		p++;
	}
	p = Pos(1,1);//reset the counter for threat assessment
	while(true)
	{
		piece* pc = (piece*) vec[p.getX()][p.getY()].getPiece();
		if(pc)
		{
			Pos k = myLiege->getPos();
			Pos& kp = k;
			if( (pc->getColour() != myLiege->getColour()) && (pc->canGo(kp, vec)))
			{
				return true;
			}

		}
		if (p.endboard())
		{
			break;
		}
		p++;
	}
	return false;
}

bool piece::canMove(BD& vec) const
{
	if (getMoves(vec).empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void piece::setPos(Pos& to, BD& vec)
{
	int x = to.getX();
	int y = to.getY();
	vec[x][y].setID(this);
	at = to;
}

int piece::getValue() const
{
	return pointvalue;
}

void piece::setMoved()
{
	firstMove = false;
}


piece::~piece()
{

}

void piece::printMe() const
{
	std::cout<< "Piece ";
	std::cout<< (getID().getID());
	std::cout<<  std::endl;
	std::cout<< "   ";
	switch (getType())
	{
	case pieceID::Pawn: std::cout << "Pawn";break;
	case pieceID::Bishop: std::cout << "Bishop";break;
	case pieceID::Knight: std::cout << "Knight";break;
	case pieceID::Rook: std::cout << "Rook";break;
	case pieceID::Queen: std::cout << "Queen";break;
	case pieceID::King: std::cout << "King";break;
	case pieceID::UNDEFINED: std::cout << "LOLWUT?";break;
	}
	std::cout<<  std::endl;
	std::cout<< "   ";
	std::cout<< "Colour = ";
	std::cout<< getColour();
	std::cout<<  std::endl;
	std::cout<< "   ";
	std::cout<< "Position:  ";
	std::cout<< "(" << at.getX() << "," << at.getY() << ")";
	std::cout<<  std::endl;
}

bool piece::isLocked (BD& vec)
{
	Pos p(1,1);
	while (true)
	{
		if (p != at)
		{
			if (canMove(p, vec))
			{
				return false;
			}
		}
		if (p.endboard())
		{
			break;
		}
		else
		{
			p++;
		}
	}
	return true;
}

deadPieceEvent::deadPieceEvent(piece* i)
{
	id = i;
}


