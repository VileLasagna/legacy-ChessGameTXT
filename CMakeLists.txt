cmake_minimum_required(VERSION 2.8)

project(ChessBastard)
set(ChessBastard_VERSION_MAJOR 1)
set(ChessBastard_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD_REQUIRED 11)

#include_directories("src")

add_executable(${PROJECT_NAME}  "src/Bishop.cpp"
				"src/Board.cpp"
				"src/ChessText.cpp"
				"src/FatalErrorException.cpp"
				"src/GameState.cpp"
				"src/King.cpp"
				"src/Knight.cpp"
				"src/Pawn.cpp"
				"src/piece.cpp"
				"src/pieceID.cpp"
				"src/Player.cpp"
				"src/Pos.cpp"
				"src/Queen.cpp"
				"src/Rook.cpp"
				"src/Square.cpp"
	    )
