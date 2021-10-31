#include <chrono>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <thread>

#include "BoggleBoard.hpp"

static const char* DICTIONARY_FILE = "../sowpods.txt";

// class BoggleBoard
// {

// public:
// 	BoggleBoard(const std::vector<std::vector<char>>& board);
// 	bool contains(const std::string& word) const noexcept;
// };

BoggleBoard initialize_board()
{
	unsigned rows, cols;
	printf("Enter the number of rows: ");
	std::cin >> rows;
	printf("Enter the number of columns: ");
	std::cin >> cols;

	std::vector<std::vector<char>> board(rows, std::vector<char>(cols));
	for (unsigned row = 0; row < rows; ++row)
	{
		for (unsigned col = 0; col < cols; ++col)
		{
			printf("Enter the letter at row %d, column %d: ", row, col);
			std::cin >> board[row][col];
		}
	}

	return BoggleBoard(board);
}

void print_words(const BoggleBoard& board, unsigned min_word_length)
{
	std::ifstream dict_file(DICTIONARY_FILE);
	std::string word;
	while (dict_file >> word)
	{
		if (word.length() < min_word_length)
		{
			continue;
		}

		if (board.contains(word))
		{
			printf("%s\n", word.c_str());
		}
	}
}

int main()
{
	printf("Enter the minimum word length: ");
	unsigned min_word_length;
	std::cin >> min_word_length;

	BoggleBoard board = initialize_board();

	printf("Now wait for 5 seconds...\n");
	std::this_thread::sleep_for(std::chrono::seconds(5));

	print_words(board, min_word_length);

	return 0;
}
