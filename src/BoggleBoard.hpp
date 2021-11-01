#ifndef BOGGLEBOARD_HPP
#define BOGGLEBOARD_HPP

#include <array>
#include <string>
#include <vector>

class BoggleBoard
{

public:
	BoggleBoard(const std::vector<std::vector<char>>& board);
	bool contains(const std::string& word) const noexcept;

private:
	const std::vector<std::vector<char>> _board;
	mutable std::vector<std::vector<bool>> _visited;
	std::array<std::vector<unsigned>, 26u> _starting_squares;
	constexpr static std::array<std::array<int, 2u>, 8u> NEIGHBORS = {
		{{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}
	};

	bool contains(const std::string& word, unsigned row, unsigned col, unsigned index) const noexcept;
	inline bool is_valid_square(unsigned row, unsigned col) const noexcept;
};

#endif
