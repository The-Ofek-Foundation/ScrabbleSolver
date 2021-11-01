#include <array>
#include <vector>
#include <string>

#include "BoggleBoard.hpp"

BoggleBoard::BoggleBoard(const std::vector<std::vector<char>>& board)
	: _board(board), _visited(_board.size(), std::vector<bool>(_board[0].size(), false))
{
	for (unsigned row = 0u; row < _board.size(); ++row)
	{
		for (unsigned col = 0u; col < _board[row].size(); ++col)
		{
			_starting_squares[_board[row][col] - 'a'].emplace_back(row * _board[row].size() + col);
		}
	}
}

bool BoggleBoard::contains(const std::string& word) const noexcept
{
	for (const auto& square : _starting_squares[word[0u] - 'a'])
	{
		unsigned row = square / _board[0].size();
		unsigned col = square % _board[0].size();
		unsigned offset = word[0u] == 'q' ? 2u : 1u;

		if (contains(word, row, col, offset))
		{
			return true;
		}
	}

	return false;
}

bool BoggleBoard::contains(const std::string& word, unsigned row, unsigned col, unsigned index) const noexcept
{
	_visited[row][col] = true;

	for (const auto& neighbor : NEIGHBORS)
	{
		unsigned next_row = row + neighbor[0u];
		unsigned next_col = col + neighbor[1u];

		if (is_valid_square(next_row, next_col) && _board[next_row][next_col] == word[index])
		{
			if (word[index] == 'q')
			{
				if (index == word.size() - 2u || contains(word, next_row, next_col, index + 2u))
				{
					_visited[row][col] = false;
					return true;
				}
			}

			if (index == word.size() - 1u || contains(word, next_row, next_col, index + 1u))
			{
				_visited[row][col] = false;
				return true;
			}
		}
	}

	_visited[row][col] = false;
	return false;
}

bool BoggleBoard::is_valid_square(unsigned row, unsigned col) const noexcept
{
	return row < _board.size() && col < _board[row].size() && !_visited[row][col];
}
