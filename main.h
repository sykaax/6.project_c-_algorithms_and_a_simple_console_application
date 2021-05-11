#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <iterator>
#include <cmath>

#include "constants.h"
namespace simple3d{

struct poin3d_struct{
	int x{};
	int y{};
	int z{};
};

poin3d_struct get_point3d_from_user();

}
int casual_random_int( int seed);
std::bitset<8> get_bits8_from_user();
std::string get_string_from_user();
std::string  get_string_line_from_user();

std::size_t get_size_t_from_user();
int get_int_from_user();
char get_char_from_user();

double get_double_from_user();

void start_func(std::string);
void finish_func(std::string);
#endif