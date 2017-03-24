/*
 * King.h
 *
 *  Created on: 19-Nov-2008
 *      Author: Vile Lasagna
 */

#include "piece.h"


#ifndef KING_H_
#define KING_H_

typedef std::vector<Square> column;
typedef std::vector<column> BD;

class King: public piece
{

public:

	bool canGo(Pos& to, BD& vec) const override;
	bool canMove(Pos& to, BD& vec) const override;
	std::vector<Pos> getMoves(BD& vec) const override;
	bool castle (bool queenside, BD& vec);
	King(Pos p);

};

#endif /* KING_H_ */
