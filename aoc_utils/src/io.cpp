#include "aoc_utils/io.hpp"

#include <vector>
#include <fstream>
#include <string>
#include <cinttypes>
std::vector<std::string> utils::read_puzzle(std::string path){

	std::ifstream file(path);
	if (!file){
		throw std::runtime_error("File not found!");
	}

	auto result = std::vector<std::string>();
	std::string line;

	while (std::getline(file, line)){
		result.push_back(line);
	}

	file.close();
	return result;
}

std::vector<std::string> utils::split(std::string& input, std::string delimiter){
	auto result = std::vector<std::string>();
	size_t start = 0;
	size_t end = input.find(delimiter);

	while(end != std::string::npos){
		result.push_back(input.substr(start, end-start));
		start = end + delimiter.length();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));
	return result;
}
