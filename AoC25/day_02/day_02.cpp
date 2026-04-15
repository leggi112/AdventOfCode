#include "day_02.hpp"
#include "aoc_utils/io.hpp"

#include <iostream>
#include <vector>
#include <cinttypes>
#include <string>

void AoC25::Day02::run(){
	long first = AoC25::Day02::solve_part_one();
	long second = AoC25::Day02::solve_part_two();

	std::cout << "Day 2 in 2025:" << std::endl;
	std::cout << "   1: " << first << std::endl;
	std::cout << "   2: " << second << std::endl;

}

long AoC25::Day02::solve_part_one(){
	auto puzzle = AoC25::Day02::get_puzzle();
	long result = 0;
	std::string current_str;
	long start, end, half;

	for (auto range : puzzle){
		start = stol(range.first);
		end = stol(range.second);

		for (long current = start; current <= end; current++){
			current_str = std::to_string(current);
			half = current_str.length() / 2;
			if (current_str.length()%2 == 0){
				if (current_str.substr(0, half) == current_str.substr(half, current_str.length())){
					
					result += current;
				}
			}
		}
	}
	return result;
}

long AoC25::Day02::solve_part_two(){
	return -1;
}

// Helpers for the day
std::vector<std::pair<std::string, std::string>> AoC25::Day02::get_puzzle(){
	auto raw_puzzle = utils::read_puzzle("./AoC25/day_02/puzzle.txt")[0];
	
	auto result = std::vector<std::pair<std::string, std::string>>();
	std::pair<std::string, std::string> element;
	
	auto ranges = utils::split(raw_puzzle, ",");
	
	std::vector<std::string> buffer;
	for (auto range : ranges){
		buffer = utils::split(range, "-");
		if (buffer.size() != 2){
			throw -1;
		}
		element = std::pair<std::string, std::string>(buffer[0], buffer[1]);
		result.push_back(element);
	}
	return result;
}
