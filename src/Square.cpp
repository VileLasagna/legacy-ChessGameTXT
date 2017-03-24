/*
 * Square.cpp
 *
 *  Created on: 17-Nov-2008
 *      Author: Vile Lasagna
 */

#include "Square.h"


bool Square::getColour() const
{
	return Colour;
}

const void* Square::getPiece() const
{
	return current_Piece;
}

const Pos Square::getPos()
{
	return pos;
}

void Square::setID(void* p)
{
	current_Piece = p;
}

const void* Square::getPassant()
{
	return enPassant;
}

void Square::setPassant(void* ep)
{
	enPassant = ep;
}

Square::Square()
{
	//std::cout << "Creating a square!" <<std::endl;
	static bool S_COLOUR = false;
	static Pos S_POS = Pos(1,1);

	Colour = S_COLOUR;
	pos = S_POS;
	current_Piece = 0;
	enPassant = 0;
	S_COLOUR = !S_COLOUR;
	S_POS++;

}

Square::Square(Pos p)
{
	//std::cout << "Creating a square!" <<std::endl;
	pos = p;
	Colour = false;
	current_Piece = 0;
	enPassant = 0;
}

//Square::Square (Square& s)
//{
//	pos = s.getPos();
//	current_piece = s.getPiece();
//	enPassant = s.getPassant();
//	colour = s.getColour();
//}

typedef std::vector<Square> column;
typedef std::vector<column> BD;

BD Square::BDClone(BD& vec)
{
	BD clone;
	column c;
	clone.push_back(c);
	for (unsigned int i = 1; i < vec.size(); i++)
	{
		clone.push_back(vec[i]);
		//clone[i].push_back(vec[i][1]);
	}
	return clone;
}
