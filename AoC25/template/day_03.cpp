#include "day_03.hpp"
#include "aoc_utils/io.hpp"

#include <iostream>
#include <vector>
#include <cinttypes>
#include <string>

void AoC25::Day03::run(){
	std::cout << "Day 3 in 2025:" << std::endl;

	long first = AoC25::Day03::solve_part_one();
	std::cout << "   1: " << first << std::endl;

	long second = AoC25::Day03::solve_part_two();
	std::cout << "   2: " << second << std::endl;
}

long AoC25::Day03::solve_part_one(){
	return -1;
}

long AoC25::Day03::solve_part_two(){
	return -1;
}

// Helpers for the day
std::vector<std::string> AoC25::Day03::get_puzzle(){
	auto raw_puzzle = utils::read_puzzle("./AoC25/day_03/puzzle.txt");
	
	auto result = std::vector<std::string>();
	for (auto line : raw_puzzle){
		result.push_back(line);
	}
	return result;
}
