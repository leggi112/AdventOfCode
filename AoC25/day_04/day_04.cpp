#include "day_04.hpp"
#include "aoc_utils/io.hpp"

#include <iostream>
#include <vector>
#include <cinttypes>
#include <string>

long solve_without_replace_4_25(std::vector<std::string>& puzzle);
long solve_with_replace_4_25(std::vector<std::string>& puzzle);

void AoC25::Day04::run(){
	std::cout << "Day 4 in 2025:" << std::endl;

	long first = AoC25::Day04::solve_part_one();
	std::cout << "   1: " << first << std::endl;

	long second = AoC25::Day04::solve_part_two();
	std::cout << "   2: " << second << std::endl;
}

long AoC25::Day04::solve_part_one(){
	auto puzzle = AoC25::Day04::get_puzzle();
	return solve_without_replace_4_25(puzzle);
}

long AoC25::Day04::solve_part_two(){
	auto puzzle = AoC25::Day04::get_puzzle();
	auto last_puzzle = puzzle;
	long result = 0;

	do {
		last_puzzle = puzzle;
		result += solve_with_replace_4_25(puzzle);

	} while (puzzle != last_puzzle);
	
	return result;
}

// Helpers for the day
std::vector<std::string> AoC25::Day04::get_puzzle(){
	return utils::read_puzzle("./AoC25/day_04/puzzle.txt");
}

long solve_without_replace_4_25(std::vector<std::string>& puzzle){
	long result = 0;
	for (size_t i  = 0; i < puzzle.size(); i++){
		for (size_t j = 0; j < puzzle[i].length(); j++){
			if (puzzle[i][j] != '@'){continue;}
			
			int x, y;
			int neighbours = 0;

			for (int n = 0; n < 9; n++){
				if (n == 4){continue;}
				x = j + (n % 3) - 1;
				y = i + (n / 3) - 1;
				if (x < 0 || x >= puzzle[i].length()){continue;}
				if (y < 0 || y >= puzzle.size()){continue;}

				if (puzzle[y][x] == '@'){neighbours++;}
			}
			if (neighbours < 4){result++;}
		}
	}
	return result;
}

long solve_with_replace_4_25(std::vector<std::string>& puzzle){
	long result = 0;
	auto new_puzzle = puzzle;
	for (size_t i  = 0; i < puzzle.size(); i++){
		for (size_t j = 0; j < puzzle[i].length(); j++){
			if (puzzle[i][j] != '@'){continue;}
			
			int x, y;
			int neighbours = 0;

			for (int n = 0; n < 9; n++){
				if (n == 4){continue;}
				x = j + (n % 3) - 1;
				y = i + (n / 3) - 1;
				if (x < 0 || x >= puzzle[i].length()){continue;}
				if (y < 0 || y >= puzzle.size()){continue;}

				if (puzzle[y][x] == '@'){neighbours++;}
			}
			if (neighbours < 4){
				result++;
				new_puzzle[i][j] = '.';
			}
		}
	}
	puzzle = new_puzzle;
	return result;
}


