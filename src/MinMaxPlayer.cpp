//
//  MinMaxPlayer.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "MinMaxPlayer.hpp"

#include <cassert>
#include <climits>
#include <cstdlib>
#include <vector>

Position MinMaxPlayer::getNextMove(Board const& board, Field current_field) {
	std::vector<Position> possible_moves = board.getEmptyPositions();
	
	assert(!possible_moves.empty());

	/*for(int i=0;i<possible_moves.size;i++){
		getMinMaxScore(board, current_field);
	}*/

    return Position::unknown_position; // you need to change this in your implementation
}

int MinMaxPlayer::getMinMaxScore(Board const& board, Field current_field) {
	int score = -1000;
	

    return 0; // you need to change this in your implementation
}

