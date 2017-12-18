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
	int bestScore = -100000;
	int bestMove = 0;
	for (int i = 0; i < possible_moves.size(); i++) {
		Board next_board = board;
		next_board.doMove(possible_moves[i], current_field);
		
		int score = -getMinMaxScore(next_board, ~current_field);
		if (score > bestScore) {
			bestMove = i;
			bestScore = score;
		}
	}
	return possible_moves[bestMove]; // you need to change this in your implementation
	
}

int MinMaxPlayer::getMinMaxScore(Board const& board, Field current_field) {
	
	//is spel voorbij
	if (board.isWinner(current_field)) {
		return 10;
	}
	else if (board.isWinner(~current_field)) {
		return -10; 
	}
	else if (board.isFull()) {
		return 0;
	}
	std::vector<Position> possible_moves = board.getEmptyPositions();
	int best_score = -10000;
	for (int i = 0; i < possible_moves.size(); i++) {
		 
		
		Board next_board = board;
		next_board.doMove(possible_moves[i], current_field);

		int score = -getMinMaxScore(next_board, ~current_field);
		if (score > best_score) {
			best_score = score;
		}
		
	}
	
	return best_score; // you need to change this in your implementation 
}
