#include "day_03.hpp"
#include "aoc_utils/io.hpp"

#include <iostream>
#include <vector>
#include <cinttypes>
#include <string>

long solve_line_2_3_25(const std::string& line);

size_t max_3_25(const std::string& str);

void AoC25::Day03::run(){
	std::cout << "Day 3 in 2025:" << std::endl;

	long first = AoC25::Day03::solve_part_one();
	std::cout << "   1: " << first << std::endl;

	long second = AoC25::Day03::solve_part_two();
	std::cout << "   2: " << second << std::endl;
}

long AoC25::Day03::solve_part_one(){
	auto puzzle = AoC25::Day03::get_puzzle();
	long result = 0;
	int first, second;
	std::string sub;
	size_t first_index;

	for (auto line : puzzle){
		first_index = max_3_25(line.substr(0, line.length()-1));
		first = std::stoi(line.substr(first_index, 1));
		sub = line.substr(first_index + 1, line.length()-first_index+1);
		second = std::stoi(sub.substr(max_3_25(sub), 1));
		result += first * 10 + second;
	}
	return result;
}

long AoC25::Day03::solve_part_two(){
	auto puzzle = AoC25::Day03::get_puzzle();
	
	long result = 0;

	for (auto line : puzzle){
		result += solve_line_2_3_25(line);
	}
	return result;
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

size_t max_3_25(const std::string& str){
	uint8_t last = str[0];
	uint8_t current;
	size_t last_index = 0;
	for (size_t current_index = 1; current_index <str.length(); current_index++){
		current = str[current_index];
		if (last >= current){continue;}

		last = current;
		last_index = current_index;
	}
	return last_index;
}

long solve_line_2_3_25(const std::string& line){
	std::string result = "123456789abc";
	size_t start = 0;
	size_t end = line.length() - 12;
	std::string relevant_str = line;
	size_t index = 0;

	for (size_t i = 0; i < 12; i++){

		relevant_str = line.substr(start, end-start+1);

		index = max_3_25(relevant_str);
		result[i] = relevant_str[index];

		start += index + 1;
		end++;
	}
	return std::stol(result);
}
