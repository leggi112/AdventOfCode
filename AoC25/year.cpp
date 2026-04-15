#include "year.hpp"
#include "day_01/day_01.hpp"
#include "day_02/day_02.hpp"
#include <iostream>

void AoC25::run_year(){
	std::cout << "Year 2025:" << std::endl;
	AoC25::Day01::run();
	std::cout << std::endl;
	AoC25::Day02::run();
	std::cout << std::endl;
}
