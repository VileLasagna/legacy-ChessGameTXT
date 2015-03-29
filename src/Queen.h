/*
 * Queen.h
 *
 *  Created on: 19-Nov-2008
 *      Author: Vile Lasagna
 */

#include "piece.h"


#ifndef QUEEN_H_
#define QUEEN_H_

typedef std::vector<Square> column;
typedef std::vector<column> BD;

class Queen: public piece
{
public:

	const bool canGo(Pos& to, BD& vec);
	const bool canMove(Pos& to, BD& vec);
	const std::vector<Pos> getMoves(BD& vec);
	Queen(Pos p);
	Queen(Pos p, bool c);

private:

	const bool BishopMove (Pos& to, BD& vec);
	const bool RookMove (Pos& to, BD& vec);
	const std::vector<Pos> getBishop(BD& vec);
	const std::vector<Pos> getRook(BD& vec);

};

#endif /* QUEEN_H_ */
