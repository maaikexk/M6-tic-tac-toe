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
	int bestScore = -1000;
	int bestMove;
	bool maxPlayer = true;

	assert(!possible_moves.empty());

	for (int i = 0; i < possible_moves.size(); i++) {
		Board new_board = board;
		new_board.doMove(possible_moves[i], current_field);

		int moveScore = getMinMaxScore(new_board, current_field, maxPlayer);

		if (moveScore > bestScore) {
			bestMove = i;
			bestScore = moveScore;
		}
	}
	return possible_moves[bestMove]; // you need to change this in your implementation
}

int MinMaxPlayer::getMinMaxScore(Board board, Field current_field, bool maxPlayer) {
	int score = -1000;

	if (board.isWinner(current_field)) {
		return 10;
	}

	if (board.isWinner(~current_field)) {
		return -10;
	}

	if (board.isFull()) {
		return 0;
	}

	std::vector<Position> possible_moves = board.getEmptyPositions();

	int bestScore = -1000;

	if (maxPlayer) {
		for (int i = 0; i < possible_moves.size(); i++) {
			board.doMove(possible_moves[i], current_field);
			score = (getMinMaxScore(board, current_field, false));

			if (score > bestScore) {
				bestScore = score;
			}
			board.doMove(possible_moves[i], Field::Empty);
		}
	}
	if (!maxPlayer) {
		for (int i = 0; i < possible_moves.size(); i++) {
			board.doMove(possible_moves[i], ~current_field);
			score = (getMinMaxScore(board, current_field, true));

			if (score > bestScore) {
				bestScore = score;
			}
			board.doMove(possible_moves[i], Field::Empty);
		}
	}
	return bestScore;
}


