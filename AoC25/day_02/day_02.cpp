#include "day_02.hpp"
#include "aoc_utils/io.hpp"

#include <iostream>
#include <vector>
#include <cinttypes>
#include <string>
#include <regex>

bool is_valid_2_2_25(const std::string& id);

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

	auto puzzle = AoC25::Day02::get_puzzle();	
	long result = 0;
	std::string current_str;
	long start, end;

	for (auto range : puzzle){
		start = stol(range.first);
		end = stol(range.second);

		for (long current = start; current <= end; current++){
			current_str = std::to_string(current);
			result += is_valid_2_2_25(current_str) ? 0 : current;
		}
	}
	return result;
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

bool is_valid_2_2_25(const std::string& id){
	std::string test;
	for (size_t i = 1; i <= id.length()/2; i++){
		if (id.length() % i != 0){continue;}
		test = std::regex_replace(id, std::regex(id.substr(0, i)), "");
		if (test == ""){return false;}
	}
	return true;
}
