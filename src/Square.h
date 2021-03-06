/*
 * square.h
 *
 *  Created on: 29-Oct-2008
 *      Author: Vile Lasagna
 */

#include "Pos.h"
#include "pieceID.h"
#include <iostream>
#include <vector>

#ifndef SQUARE_H_
#define SQUARE_H_


class Square
{
public:
	

	bool getColour() const;
	const void* getPiece() const;//returns the ID of the current piece in this square
	const Pos getPos();
	void setID(void* p);
	Square();
	Square(Pos p);
	//Square(Square& s);
	const void* getPassant();
	void setPassant(void* ep);
	static std::vector<std::vector <Square> > BDClone(std::vector<std::vector <Square> >& vec);

private:
	/*
	 * The static versions are used for creation of the vector
	 * in board class
	 */
	static bool S_COLOUR;
	static Pos S_POS;
	void* enPassant; //Pointer to a pawn that may be captured enPassant in this square (if any).
	bool Colour;
	Pos pos;
	void* current_Piece;//Pointer to a piece currently occupying this square (if any)
};






#endif /* SQUARE_H_ */

