/*
 * ChessText.cpp
 *
 *  Created on: 10-Nov-2008
 *      Author: Vile Lasagna
 */

#include "GameState.h"
#include <iostream>
#include <String>

char getSquareChar(Square s)
{
	piece* p = (piece*) s.getPiece();
	if (!p)
	{
		return ' ';
	}
	else
	{
		if (p->getColour())
		{
			switch (p->getType())
			{
			case pieceID::Pawn: return 'P';
			case pieceID::Bishop: return 'B';
			case pieceID::Knight: return 'N';
			case pieceID::Rook: return 'R';
			case pieceID::Queen: return 'Q';
			case pieceID::King: return 'K';
			case pieceID::UNDEFINED: return '?';
			}
		}
		else
		{
			switch (p->getType())
			{
			case pieceID::Pawn: return 'p';
			case pieceID::Bishop: return 'b';
			case pieceID::Knight: return 'n';
			case pieceID::Rook: return 'r';
			case pieceID::Queen: return 'q';
			case pieceID::King: return 'k';
			case pieceID::UNDEFINED: return '?';
			}
		}
	}
	return '#';
}

void paint(GameState& g)
{
	char canvas[80][25];
	for (int i = 0; i <25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			canvas[j][i] = ' ';
		}
	}
	//Loops that draw the board
	for(int i = 1; i <= 17; i+=2)
	{
		for(int j = 3; j <= 51; j++)
		{
			canvas[j][i] = '-';
		}
	}
	for(int i = 2; i <= 16; i+=2)
	{
		for(int j = 3; j <= 51; j+=6)
		{
			canvas[j][i] = '|';
		}
	}
	//Board Drawing END
	//Start Text

	canvas [6][0] = 'a';
	canvas [12][0] = 'b';
	canvas [18][0] = 'c';
	canvas [24][0] = 'd';
	canvas [30][0] = 'e';
	canvas [36][0] = 'f';
	canvas [42][0] = 'g';
	canvas [48][0] = 'h';

	canvas [1][2] = '8';
	canvas [1][4] = '7';
	canvas [1][6] = '6';
	canvas [1][8] = '5';
	canvas [1][10] = '4';
	canvas [1][12] = '3';
	canvas [1][14] = '2';
	canvas [1][16] = '1';

	canvas [6][18] = 'a';
	canvas [12][18] = 'b';
	canvas [18][18] = 'c';
	canvas [24][18] = 'd';
	canvas [30][18] = 'e';
	canvas [36][18] = 'f';
	canvas [42][18] = 'g';
	canvas [48][18] = 'h';

	canvas [53][2] = '8';
	canvas [53][4] = '7';
	canvas [53][6] = '6';
	canvas [53][8] = '5';
	canvas [53][10] = '4';
	canvas [53][12] = '3';
	canvas [53][14] = '2';
	canvas [53][16] = '1';

	if(g.getTurn())
	{
		canvas[6][20] = 'W';
		canvas[7][20] = 'h';
		canvas[8][20] = 'i';
		canvas[9][20] = 't';
		canvas[10][20] = 'e';
	}
	else
	{
		canvas[6][20] = 'B';
		canvas[7][20] = 'l';
		canvas[8][20] = 'a';
		canvas[9][20] = 'c';
		canvas[10][20] = 'k';
	}


	canvas[12][20] = 'P';
	canvas[13][20] = 'l';
	canvas[14][20] = 'a';
	canvas[15][20] = 'y';
	canvas[16][20] = 's';
	canvas[17][20] = ':';

	int c = g.getCheck();
	if(c)
	{

		canvas[62][5] = 'i';
		canvas[63][5] = 's';
		canvas[64][5] = ' ';
		canvas[65][5] = 'i';
		canvas[66][5] = 'n';

		canvas[62][6] = 'C';
		canvas[63][6] = 'h';
		canvas[64][6] = 'e';
		canvas[65][6] = 'c';
		canvas[66][6] = 'k';
		canvas[67][6] = '!';

		if (c == 1)
		{
			canvas[62][4] = 'W';
			canvas[63][4] = 'h';
			canvas[64][4] = 'i';
			canvas[65][4] = 't';
			canvas[66][4] = 'e';
		}
		if (c == 2)
		{
			canvas[62][4] = 'B';
			canvas[63][4] = 'l';
			canvas[64][4] = 'a';
			canvas[65][4] = 'c';
			canvas[66][4] = 'k';
		}
	}



	for (int i = 1; i <= 8; i++)
	{
		for(int j = 1; j <= 8; j++)
		{
			char c = getSquareChar((g.getField())[j][i]);
			canvas [6*j][(18 - (2*i))] = c;
		}
	}
	std::cout<<std::endl;
	for (int i = 0; i <25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			std::cout<< canvas[j][i];
		}
		std::cout<<std::endl;
	}

}

bool welcome()
{
	std::cout<< "Welcome to ChessBastard 2008" <<std::endl<<std::endl<<std::endl;
	std::cout<< "Would you like some instructions?" <<std::endl;
	std::cout<< "1-> " << "Instructions?!?! You you're going to try and teach ME how to play chess?!?"<<std::endl;
	std::cout<< "2-> " <<  "Okay, I can play chess, but how do YOU work?"<<std::endl;
	std::cout<< "3-> " <<  "CHESS Bastard? You mean that thing like checkers?"<<std::endl;
	int i = 0;
    while (true)
	{
	/*
	 * Choose an option player, but don't just go entering anything you fancy ¬¬;
     */

		std::cin >> i;
		if (std::cin.fail())
		{
    		std::cout << "Please enter a valid number"<<std::endl;
    		std::cin.clear();
    		std::string a;
    		std::cin >> a;
		}
		else 
		{
			if (i == 1) 
			{
				break;
			}
			if (i == 2) 
			{
				break;
			}
			if (i == 3) 
			{
				break;
			}
		}
	}
	//I'd make a switch but it'll just look awkward
	std::cout << std::endl;
	if (i == 1)
	{
		std::cout << "Well aren't you so smart? Off you go then, prick!" << std::endl;
		system("pause");
		return true;
	}

	if (i == 2)
	{
		std::cout << "Well, you silly, you play me like you play real chess!" <<std::endl;
		std::cout << "To make a move you type your move, just like you would annotate chess" <<std::endl;
		std::cout << "There ARE, though, some... particularities." << std::endl;
		std::cout << "First of all, you always have to type P when you're moving a pawn." << std::endl;
		std::cout << "Also, you don't have to indicate that you're putting your oppoent in check, " << std::endl;
		std::cout << "that you are taking a piece or anything like that. Just state your moves." << std::endl;
		std::cout << "If any of these particularities do not suit you, go and find yourself a REAL" << std::endl  <<"chessboard!" << std::endl;
		std::cout << "I am sure you will eventually find out they are all for the bet." << std::endl  <<"Let the game commence!" <<std::endl;
		system("pause");
		return true;
	}

	if (i == 3)
	{
		std::cout << "NO!!!"<<std::endl;
		std::cout << "Chess is a game of tactics, intelligence, tradition, elegance, foresight," << std::endl  <<"cunning and boldness!" << std::endl;
		std::cout << "Don't you DARE compare me to that barbaric child's play for people " << std::endl  <<"that can't differentiate two" << std::endl;
		std::cout << "colours of squares or keep track of more than two kinds of pieces!!!" << std::endl << std::endl;
		std::cout << "Chess is a game representing the clash between two armies." << std::endl  <<"As the King and leader of one of these" <<std::endl;
		std::cout << "your objective is to capture the enemy King (and subsequently execute him" << std::endl  <<"in the town square)" << std::endl;
		std::cout << "Of course, you are not alone on this endeavor (neither is your enemy)" << std::endl  <<"and have many servants to aid you" << std::endl;
		std::cout << "In ChessBastard pieces are represented by letters on the board." << std::endl  <<"Capitals are the White pieces. " << std::endl;
		std::cout << "The King (K) is the most important piece of the game." << std::endl  <<"You can never allow your enemy to be able to attack it. " << std::endl;
		std::cout << "If your King is threatened you must protect it at once." << std::endl  <<"If you can't, you lose the game. " << std::endl;
		std::cout << "(and subsequently executed in the town square. I'd vote for impaling)" << std::endl;
		std::cout << "In chess, each player moves once, with White taking the first move always." <<std::endl;
		std::cout << "Every piece moves in a different way. You, the King, can move to any direction" << std::endl  <<"but only one step at a time" << std::endl;
		std::cout << "(All those banquets won't have seen like a good idea once YOU'RE in the run...)" << std::endl;
		system ("pause");
		std::cout << std::endl <<"The majority of your army is composed by weakly, silly pawns (P)" << std::endl;
		std::cout << "A meat shield as good as any but lacking in versatility." << std::endl  <<"They can only move forward, one square at a time." <<std::endl;
		std::cout << "They do spend their idle time building some suicidal momentum, though," << std::endl  <<"all for your... enjoyment." <<std::endl;
		std::cout << "When you first move a pawn, you may have it advance two squares instead of one." <<std::endl;
		std::cout << "Very useful but this recklessness is not without a price." <<std::endl;
		std::cout << "Of all your soldiers Pawns are the only ones that have a special way " << std::endl  <<"of slaying their foes" <<std::endl;
		std::cout << "While all other pieces, including you, need only walk over your enemy, " << std::endl  <<"if the pawn finds an enemy";
		std::cout << " in front of him, he is powerless!" << std::endl  <<"When, and ONLY when capturing, a pawn takes also a step to a side" << std::endl;
		std::cout << "so that it captures in a diagonal way." <<std::endl;
		std::cout << "This brings us back to the recklessness of charging blindly through battlefields" << std::endl  <<"When your pawn takes ";
		std::cout << "a double move and ends up beside an enemy pawn " << std::endl  <<"this enemy pawn may immediately capture your pawn as if" <<std::endl;
		std::cout << "it was still passing through the first square." << std::endl  <<"'En Passant' as some git said it and everyone decided it" << std::endl;
		std::cout << "was appropriate just because it's french...." << std::endl;
		std::cout << "Your pawn also can never walk back. Their devotion is as blind as is pityful! " << std::endl  <<"But this also brings a hidden treat!" <<std::endl;
		std::cout << "Should your pawn miraculously brave all of its enemies and climb" << std::endl  <<"all the way to the end of the board" <<std::endl;
		std::cout << "A promotion awaits him and he may become any other kind of piece.... " << std::endl  <<"except a King of course, he would ";
		std::cout << "have to be executed, otherwise..." << std::endl  <<"No one needs someone else trying to rule what's yours" <<std::endl;
		system("pause");
		std::cout <<  std::endl  <<"The second kind of servant available to you is the swift Knight (N)!" << std::endl;
		std::cout << "The Knight doesn't move all too far, but that's okay " << std::endl  <<"because it has a special ability!" <<std::endl;
		std::cout << "The Knight always moves two squares in a direction and one in the other " << std::endl  <<"like an L shaped thing" <<std::endl;
		std::cout << "What's so special about it? It crosses through any unit in it's path," << std::endl  <<"friend and foe alike!" <<std::endl;
		std::cout << "If you think your pathetic wall of pawns is going to save you from Sir Lancelot" << std::endl  <<"THINK AGAIN!" <<std::endl;
		std::cout << "The Knight only captures the piece standing on the square he lands, though." << std::endl  <<"And, of course, you";
		std::cout << " can't capture your own piece." << std::endl  <<"(traitors will be fed to the hounds)" <<std::endl;
		system("pause");
		std::cout << std::endl <<"Your next weapon is one as much of faith as of steel, the Bishop (B)" <<std::endl;
		std::cout << "As any good priest, they carry holy names but we all know they're" << std::endl  <<"thirsting for blood." << std::endl;
		std::cout << "Unlike what you'd expect from most priests, though, these guys enforce" << std::endl  <<"their influence in" <<std::endl;
		std::cout << "a very military and hands-on way" << std::endl  <<"And of course this is a considerable influence that we're talking about" << std::endl;
		std::cout << "Limited only by the size of the board, the Bishop can move diagonally" << std::endl  <<"in any direction and any number";
		std::cout << "of squares that he sees fit" << std::endl  <<"(provided he is unobstructed)" << std::endl  <<"All to carry his will with swiftness and fervor!" << std::endl;
		system("pause");
		std::cout << std::endl  <<"But even the cocky bishop pales before the might of the Rook!(R)" << std::endl  <<"These juggernaut towers of doom often" <<std::endl;
		std::cout << "shift the power balance" << std::endl  <<"of the whole field whenever they move." << std::endl  <<"Usually lingering near the edges of the board," << std::endl;
		std::cout << "your very own siege engines of destruction can move any number of squares"<< std::endl  <<"either vertically or horizontally." << std::endl;
		std::cout << "Able to effectively threaten and protect at the same time" << std::endl  <<"these pieces are of prime importance in you battles." <<std::endl;
		std::cout << "Throwing them away or ignoring them may lead to decapitation." << std::endl;
		std::cout << "As if it weren't good enough, the rooks have a special move that protects you" << std::endl  <<"and brings their might to the field all at one" <<std::endl;
		std::cout << "This move is called castling, and there are some special rules for it." << std::endl;
		std::cout << "When castling, you move two squares towards the rook of your choice " << std::endl  <<"and that rook crosses over to your back" << std::endl;
		std::cout << "This brings us to our first rule of castling" << std::endl  <<"The path between you and that rook must be clear of any pieces" <<std::endl;
		std::cout << "Also, you're going to pass by one square and stand on another" << std::endl  <<"so none of these can be threatened by your enemy" << std::endl;
		std::cout << "Finally, to castle, those involved msut not have moved yet in that match" << std::endl  <<"Moving your rook takes away the option";
		std::cout << "of castling to that side" << std::endl  <<"and if YOU move you can't castle at all" << std::endl;
		system("pause");
		std::cout <<  std::endl  <<"The best is, of course, left for last."<< std::endl  <<"Your last ally is none other than your Queen (Q)" << std::endl;
		std::cout << "Each King only has one, which makes all that more precious." << std::endl  <<"While the rook shifts the balance" <<std::endl;
		std::cout << "The role of the Queen is often to drive such balance." << std::endl  <<"Always a threat, always a target, others cower before their terrible gaze!" << std::endl;
		std::cout << "The Queen can't move through pieces, but it can move any number of squares" << std::endl  <<"In any straight direction it sees fit" << std::endl;
		std::cout << "It's like if it had the power of the Bishop and the Rook combined" << std::endl  <<"But such flexibility and the sheer power" << std::endl;
		std::cout << "and strength of the danger that flows from wherever the queen is" << std::endl  <<"<ake it even more dangerous and ominous." <<std::endl;
		std::cout << "Knowing this, its no wonder 9 in 10 promoted pawns turn into Queens." << std::endl  <<"Hang on to yours, you DO need your woman!" << std::endl;
		system("pause");
		std::cout << std::endl  <<"Keeping up? I HOPE SO!" << std::endl;
		std::cout << "Now, all that's left is teaching you how to move your pieces" << std::endl;
		std::cout << "To enter a command type the letter that identifies" << std::endl  <<"the piece you're trying to move" << std::endl  <<"followed by the square you're moving to." << std::endl;
		std::cout << "Like PE4 or NF3 and such (not case sensitive)" << std::endl;
		std::cout << "I'll find the piece you're talking about if there's only one that can be it." << std::endl  <<"If there's more you need to provide me" <<std::endl;
		std::cout << "with either the collumn or the row of the one you mean" << std::endl  <<"(the one that helps, please!)" << std::endl  <<"Like Nac6 or Q2B3." <<std::endl;
		std::cout << "The first character is always the piece you're moving" << std::endl  <<"And the last two are always where you're trying to go" << std::endl;
		std::cout << "If you need (or want) you can specify exactle where that piece is"<< std::endl  <<"That's just as fine by me. (Qd3e4)" <<std::endl;
		std::cout << "When you're trying to castle you can go to your final position" << std::endl  <<"Or say 0-0-0 or  0-0, as is customary";
		std::cout << "and well know" << std::endl  <<"To those who play civilised things like CHESS."<< std::endl  <<"0-0 means 'Castle Kingside' and 0-0-0 'Castle Queenside'" <<std::endl;
		std::cout << "Don't worry about pawn promotion, I'll ask you when the time comes." << std::endl;
		std::cout << "If you must you can RESIGN or offer a DRAW at any time" << std::endl  <<"Have fun if you do... loser...." << std::endl;
		system("pause");
		std::cout << std::endl  <<"Well then, I guess there's not much more to it that I can teach you." <<std::endl;
		std::cout << "Go try and play some, see if you understand it" << std::endl  <<"And if your mind can cope with such beauty and complexity" << std::endl;
		std::cout << "go find yourself a book and study for real!" << std::endl  <<"You can't just rely on me all the time, you lazy bum!" <<std::endl;
		std::cout << "Off you go now!" << std::endl  <<"You've just found something more interesting than banging rocks together" << std::endl  <<"enjoy your newfound enlightenment!" << std::endl;
		system("pause");
		return true;
	}



}

int main()
{
	bool start = false;
	while (!start)
	{
		start = welcome();
	}
	GameState game;
	while (true)
	{
		system("cls");
		paint(game);
		String c;
		std::cin >> c;
		bool b = false;
		try
		{
			b = game.Command(c);
			game.getWin();
		}
		catch (EndGameEvent e)
		{
			system("cls");
			paint(game);
			std::cout << "Game ended" << std::endl;
			switch (e.getResult())
			{
			case EndGameEvent::WHITE: std::cout << "White Wins" << std::endl; break;
			case EndGameEvent::BLACK: std::cout << "Black Wins" << std::endl; break;
			case EndGameEvent::DRAW: std::cout << "Draw game" << std::endl; break;
			}
			switch (e.getReason())
			{
			case EndGameEvent::STALE: std::cout << "By Stalemate: Player has no available moves " << std::endl; break;
			case EndGameEvent::THREEFOLD: std::cout << "By Threefold Repetition Rule: The show must go on... " << std::endl; break;
			case EndGameEvent::MATE: std::cout << "By Checkmate: See you at the guillotine " << std::endl; break;
			case EndGameEvent::RESIGN: std::cout << "Enemy Resigned: Bloody coward... " << std::endl; break;
			case EndGameEvent::AGREE: std::cout << "Players Agreed.... sissies..." <<std::endl; break;
			}
			break;
		}

	}
	system("pause");

}


