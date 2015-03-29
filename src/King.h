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

	const bool canGo(Pos& to, BD& vec);
	const bool canMove(Pos& to, BD& vec);
	const std::vector<Pos> getMoves(BD& vec);
	bool castle (bool queenside, BD& vec);
	King(Pos p);

};

#endif /* KING_H_ */
