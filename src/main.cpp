#include <chrono>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>

#include "BoggleBoard.hpp"

static const char* DICTIONARY_FILE = "../sowpods.txt";

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

void write_word(const std::string& word)
{
	for (char c : word)
	{
		const char * command = (std::string("xdotool key ") + c).c_str();
		if (std::system(command) < 0)
		{
			std::cerr << "Error: " << strerror(errno) << std::endl;
		}
	}
	
	if (std::system("xdotool key Return") < 0)
	{
		std::cerr << "Error: " << strerror(errno) << std::endl;
	}
}

void find_words(const BoggleBoard& board, unsigned min_word_length, bool write)
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
			if (write)
			{
				write_word(word);
			}
			
			printf("%s\n", word.c_str());

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
}

int main()
{
	printf("Enter the minimum word length: ");
	unsigned min_word_length;
	std::cin >> min_word_length;

	printf("Write the words (0 = no, 1 = yes)? ");
	bool write;
	std::cin >> write;

	BoggleBoard board = initialize_board();

	if (write)
	{
		printf("Now wait for 5 seconds...\n");
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}

	find_words(board, min_word_length, write);

	return 0;
}
