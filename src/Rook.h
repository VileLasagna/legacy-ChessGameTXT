/*
 * Rook.h
 *
 *  Created on: 19-Nov-2008
 *      Author: Vile Lasagna
 */


#include "piece.h"

#ifndef ROOK_H_
#define ROOK_H_

typedef std::vector<Square> column;
typedef std::vector<column> BD;

class Rook: public piece
{
public:

	bool canGo(Pos& to, BD& vec) const override;
	bool canMove(Pos& to, BD& vec) const override;
	std::vector<Pos> getMoves(BD& vec) const override;
	Rook(Pos p);
	Rook(Pos p, bool c);

};


#endif /* ROOK_H_ */
