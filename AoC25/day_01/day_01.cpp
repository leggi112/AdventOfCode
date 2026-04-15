#include "day_01.hpp"
#include "aoc_utils/io.hpp"

#include <iostream>
#include <vector>
#include <cinttypes>


void AoC25::Day01::run(){
	long first = AoC25::Day01::solve_part_one();
	long second = AoC25::Day01::solve_part_two();

	std::cout << "Day 1 in 2025:" << std::endl;
	std::cout << "   1: " << first << std::endl;
	std::cout << "   2: " << second << std::endl;
}

long AoC25::Day01::solve_part_one(){
	auto puzzle = AoC25::Day01::get_puzzle();
	
	int dial = 50;
	long result = 0;
	for (auto line : puzzle){
		if (line.first == 'R'){
			dial = (dial + line.second) % 100;
		} else {
			dial = (dial - line.second) % 100;
		}
		if (dial == 0){result++;}
	}
	return result;
}

long AoC25::Day01::solve_part_two(){
	auto puzzle = AoC25::Day01::get_puzzle();

	int dial = 50;
	bool passed_zero = false;
	long result = 0;

	for (auto line : puzzle){
		if (line.first == 'R'){
			for (int i = 0; i < line.second; i++){
				dial++;
				if (dial == 100){
					result++;
					dial = dial%100;
				}
			}    
                             
		} else {
			for (int i = 0; i < line.second; i++){
				dial--;
				if (dial == 0){
					result++;
				} else if (dial == -1){
					dial = 99;
				}
			}
		}
	}
	return result;
}

// Helpers for the day
std::vector<std::pair<char, int>> AoC25::Day01::get_puzzle(){
	auto raw_puzzle = utils::read_puzzle("./AoC25/day_01/puzzle.txt");
	
	auto result = std::vector<std::pair<char, int>>();
	std::pair<char, int> element;
	char direction;
	int range;
	for (auto line : raw_puzzle){
		direction = line[0];
		range = std::stoi(line.substr(1, line.length() - 1));
		element = std::pair<char, int> (direction, range);
		result.push_back(element);
	}
	return result;
}
