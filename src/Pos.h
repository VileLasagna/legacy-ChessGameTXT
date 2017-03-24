/*
 * Pos.h
 *
 *  Created on: 09-Nov-2008
 *      Author: Vile Lasagna
 */

#ifndef POS_H_
#define POS_H_

class Pos
{
	/*
	 * In the board Pos should go from 1 to 8
	 * the reason behind this is to keep
	 * 0 as a special position.
	 * (0,X) should be a special column to
	 * store dead pieces and such
	 *
	 * Y has to go from 0 to 7 because of
	 * board.
	 *
	 * To simplify checking this condition
	 * endBoard returns true if x = 8 and y=7.
	 * this should avoid some silly mistakes.
	 */
public:
	unsigned short getX() const ;
	unsigned short getY() const ;
	bool endboard();
	Pos operator++(int);
	Pos (unsigned short h = 0, unsigned short v = 0);
	bool UpRight();
	bool DownRight();
	bool DownLeft();
	bool UpLeft();
	bool operator == (Pos comp);
	bool operator != (Pos comp);

private:
	unsigned short x;
	unsigned short y;
};

#endif /* POS_H_ */
