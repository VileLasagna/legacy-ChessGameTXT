/*
 * Knight.h
 *
 *  Created on: 19-Nov-2008
 *      Author: Vile Lasagna
 */

#include "piece.h"


#ifndef KNIGHT_H_
#define KNIGHT_H_

typedef std::vector<Square> column;
typedef std::vector<column> BD;

class Knight: public piece
{

public:
	
	bool canGo(Pos& to, BD& vec) const override;
	bool canMove(Pos& to, BD& vec) const override;
	std::vector<Pos> getMoves(BD& vec) const override;
	Knight(Pos p);
	Knight(Pos p, bool c);

};

#endif /* KNIGHT_H_ */
