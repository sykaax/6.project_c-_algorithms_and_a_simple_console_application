#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>

#include "constants.h"
int casual_random_int( int seed)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)) + seed);
	return (std::rand() * 0.01) * std::rand()/ 100;
}
std::bitset<8> get_bits8_from_user()
{
	std::bitset<8> bits{};
	std::cin >> bits;
	return bits;
}
std::string get_string_from_user()
{
	std::string string{};
	std::cin >> string;
	return string;
}
std::string get_string_line_from_user()
{
	// Remove the extraneous newline character so getline() doesn't think we entered an empty string
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string line{};
	std::getline(std::cin, line);
	return line;
}
std::size_t get_size_t_from_user()
{
	std::size_t num{};
	std::cin >> num;
	return num;
}
int get_int_from_user()
{
	int num{};
	std::cin >> num;
	return num;
}
char get_char_from_user()
{
	char symbol{};
	std::cin >> symbol;
	return symbol;
}
double get_double_from_user()
{
	double num{};
	std::cin >> num;
	return num;
}
void start_func(std::string name_func)
{
	std::cout << "\nStartig function: "<< name_func << "...\n \n";
}
void finish_func(std::string name_func)
{
	std::cout << "\n \nFunction: " << name_func <<" is finish to work\n";
}
namespace simple3d {

	struct poin3d_struct {
		int x{};
		int y{};
		int z{};
	};

	poin3d_struct get_point3d_from_user()
	{
		std::cout << "Enter 3d point x:";
		int num_1_x{ get_int_from_user() };
		std::cout << "\nEnter 3d point y:";
		int num_1_y{ get_int_from_user() };
		std::cout << "\nEnter 3d point z:";
		int num_1_z{ get_int_from_user() };

		return poin3d_struct{ num_1_x, num_1_y, num_1_z };
	}

}