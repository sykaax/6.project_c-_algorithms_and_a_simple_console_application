#include "main.h"
namespace points_distance 
{
	class point2d 
	{
	private:
		double m_x;
		double m_y;
	public:
		point2d(double u_x = 0.0, double u_y = 0.0) : m_x{ u_x }, m_y{ u_y } {}

		void print() const { std::cout << "\nx = " << m_x << " y = " << m_y; }

		double distanceTo( const point2d &second_class ) const
		{
			return std::sqrt((m_x - second_class.m_x) * (m_x - second_class.m_x)
							+ (m_y - second_class.m_y) * (m_y - second_class.m_y));
		}

		friend double distanceFrom( const point2d &first, const point2d &second);

	};


	double distanceFrom(const point2d &first, const point2d &second)
	{
		return std::sqrt((first.m_x - second.m_x) * (first.m_x - second.m_x)
			+ (first.m_y - second.m_y) * (first.m_y - second.m_y));

	}

	void points_distance()
	{
		
		std::cout << "\nWrite a first point x: ";
		double firstx { get_double_from_user() };

		std::cout << "\nWrite a first point y: ";
		double firsty{ get_double_from_user() };

		std::cout << "\nWrite a second point x: ";
		double secondx{ get_double_from_user() };

		std::cout << "\nWrite a second point y: ";
		double secondy{ get_double_from_user() };

		point2d first_point{ firstx, firsty };
		point2d second_point{ secondx, secondy };

		std::cout << "\nYour points is:";
		first_point.print();
		second_point.print();

		std::cout << "\ndistance between points is: " << first_point.distanceTo(second_point) ;
	}
}
namespace ball_radius_and_color {
	class ball_radius_and_color_class {

	private:
		std::string m_color{"black"};
		float m_radius{ 10.0f };

	public:
		ball_radius_and_color_class(std::string u_color = "black" , float u_radius = 10.0f)
		{
			m_color = u_color;
			m_radius = u_radius;
		}

		ball_radius_and_color_class(float u_radius = 10.0f , std::string u_color = "black")
		{
			m_color = u_color;
			m_radius = u_radius;
		}
		void print(){
			std::cout << "\ncolor: " << m_color << ", radius: " << m_radius ;
		}
	
	};
}
namespace point3d {
	class point3d_class {
	private:
		int x{};
		int y{};
		int z{};
	public:
		void setValues(int x_new, int y_new, int z_new) {
			x = x_new;
			y = y_new;
			z = z_new;
		}
		void print() {
			std::cout << "\n<" << x << ", " << y << ", " << z << ">";
		}
		bool isEqual( const point3d_class &other_point) {
			if (x == other_point.x && y == other_point.y && z == other_point.z) { return true; }
			else { return false; }
		}
	};

	void point3d() {
		std::cout << "First 3d point.\n\n";
		point3d_class first_point;
		simple3d::poin3d_struct first_point_struct{ simple3d::get_point3d_from_user() };
		first_point.setValues(first_point_struct.x, first_point_struct.y, first_point_struct.z );

		std::cout << "\nSecond 3d point.\n\n";
		point3d_class second_point;
		simple3d::poin3d_struct second_point_struct{ simple3d::get_point3d_from_user() };
		second_point.setValues(second_point_struct.x, second_point_struct.y, second_point_struct.z);
		

		if (first_point.isEqual(second_point)) 
			{ std::cout << "\nPoints are equal"; }
		else{ std::cout << "\nPoints are not equal"; }

		first_point.print();
		second_point.print();
		
	}

}
namespace how_many_items 
{
	enum class Type_of_items 
	{
		health_poitions = 2,
		torches = 5,
		arrows = 10,
	};

	void how_many_items() {
		std::array<Type_of_items, 1> player1{ };
	}
}
namespace sort_my_names 
{
	void sort_my_names() {

		std::cout << "How many names would you like to enter?";
		std::size_t length{get_size_t_from_user()};


		auto* array_of_names{ new std::string[length] };

		for (std::size_t i{}; i < length; i++)
		{
			std::cout << "\nEnter name #" << i + 1 << ": ";
			array_of_names[i] = get_string_from_user();
		}


		std::sort( array_of_names, array_of_names + length);


		std::cout << "\nHere is your sorted list: ";
		for (std::size_t i{}; i < length; i++)
		{
			std::cout << "\nName #" << i + 1 << ": " << array_of_names[i];
		}

		delete[] array_of_names;
	}
}
namespace generate_of_monsters {
	enum class MonsterRace
	{
		orc,
		ogre,
		dragon,
		gigant_spider,
		slime,
	};

	struct Monster
	{
		int id;
		MonsterRace race;
		std::string name;
		int health;
	};

	int monster_generate_race(int race_number)
	{

		if (race_number < 5000) { return 0; }
		else if (race_number < 10000) { return 1; }
		else if (race_number < 15000) { return 2; }
		else if (race_number < 20000) { return 3; }
		else { return 4; }

	}
	std::string monster_what_race(MonsterRace race)
	{
		switch (race)
		{
		case MonsterRace::orc:
			return "orc";
		case MonsterRace::ogre:
			return "ogre";
		case MonsterRace::dragon:
			return "dragon";
		case MonsterRace::gigant_spider:
			return "gigant_spider";
		case MonsterRace::slime:
			return "slime";
		default:
			return "noname";
		}
	}
	void generate_of_monsters()
	{

		Monster Torg{ casual_random_int(100) ,MonsterRace::orc , "Torg" , casual_random_int(300) };
		Monster Blurp{ casual_random_int(200) ,MonsterRace::orc , "Blurp" , casual_random_int(400) };

		Torg.race = static_cast<MonsterRace>(monster_generate_race(casual_random_int(500)));
		Blurp.race = static_cast<MonsterRace>(monster_generate_race(casual_random_int(600)));

		std::cout << "\n This " << monster_what_race(Torg.race) << " is named " << Torg.name << " and has " << Torg.health << " health .";
		std::cout << "\n This " << monster_what_race(Blurp.race) << " is named " << Blurp.name << " and has " << Blurp.health << " health.";

	}
}
void bits8_rotate_left()
{
	std::cout << "Write a your's 8 bits: ";
	std::bitset<8> bits{ get_bits8_from_user() };
	
	std::cout << "\nHow much bits to the left will rotate these bits?: ";
	int count_of_rotate_left_bits{ get_int_from_user() };

	while (count_of_rotate_left_bits > 0)
	{
		bits = ((bits << 1) | (bits >> 7));
		count_of_rotate_left_bits--;
	}

	std::cout << "\nYour bits result is " << bits;

}
void ball_falls_from_the_tower()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height{ get_double_from_user() };

	double current_height{ height };
	double current_second{};

	while (current_height > 0)
	{
		std::cout << "\nAt " << current_second << " seconds, the ball is at height: "<< current_height << " meters" ;
		current_second ++;
		current_height = height - ((current_second * current_second) * (gravity /2));
	}

	std::cout << "\nAt " << current_second << " seconds, the ball is on the ground.";

}
void calculate_two_float_num()
{
	std::cout << "Write first float number: ";
	double num1{ get_double_from_user() };
	
	std::cout << "\nWrite an operator to calculate +, -, *, / : ";
	char oper{ get_char_from_user() };

	std::cout << "\nWrite secont float number: ";
	double num2{ get_double_from_user() };

	double result{};
	switch (oper)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
	}

	std::cout << "\nResult: " << num1 << " " << oper << " " << num2 << " = " << result;
}
void memory_cheat()
{
	std::cout << "Write some intenger number: ";
	int num{get_int_from_user()};

	std::cout << "\nyour number " << num << " has memory address is - " << &num 
			  << "\ntry to change value on that address and write some number for continue program: ";

	get_int_from_user();

	std::cout << "\nyour number now is " << num << " and has memory address is - " << &num;
	
}
void time_of_name()
{
	std::cout << "Write your full name: ";
	std::string name{ get_string_line_from_user() };

	std::cout << "\nWrite your age: ";
	double age{ get_double_from_user() };

	std::cout << "\nYou've lived " << age / name.length() << " years for each letter in your name.";
}
void even_or_odd_int()
{
	std::cout << "Write an integer to check if it is even or odd: ";

	int num{ get_int_from_user() };

	std::cout << "\nNumber " << num << " is " << ( (num % 2) ? "odd." : "even.") ;
}
void invest_counter()
{
	std::cout << "Write your investment amount of money: ";
	double amount_money{ get_double_from_user() };

	std::cout << "\nHow many days will the withdrawal and reinvestment cycle of money take ?: ";
	int reinvest_days{ get_int_from_user() };

	std::cout << "\nHow much is the investment income percentage?: ";
	double percent_income{ get_double_from_user() };

	std::cout << "\nHow much money do you want to add each new cycle?: ";
	double add_money{ get_double_from_user() };

	std::cout << "\nHow many days do you want to spend on these reinvestment cycles?: ";
	int total_days{ get_int_from_user() };

	// count how many cycles we have time to complete
	int count_cycles = total_days / reinvest_days;
	
	// we start a cycle that will calculate the profitability
	int i{0};
	double amount_money_result{ amount_money };
	double amount_money_result_without_invest{};
	while( i < count_cycles )
	{
		amount_money_result = (add_money + amount_money_result) * (1.0 + (percent_income / 100.0));
		amount_money_result_without_invest = add_money + amount_money_result_without_invest;
		i++;
	}
	
	std::cout << "\nYou will have time to complete " << count_cycles << " reinvestment cycles. After " << total_days
			  << " days, your " << amount_money << " + (" << amount_money_result_without_invest 
		      << ") money turns into " << amount_money_result << " money. ";

}
void plus_minus_double()
{
	std::cout << "Write your first float number: ";
	double num_1{ get_double_from_user() };

	std::cout << "\nWrite your second float number: ";
	double num_2{ get_double_from_user() };

	std::cout << '\n' << num_1 << " + " << num_2 << " is " << num_1 + num_2
			  << '\n' << num_1 << " - " << num_2 << " is " << num_1 - num_2;
}
void plus_minus_num()
{
	std::cout << "Write your first number: ";
	int num_1{ get_int_from_user() };

	std::cout << "\nWrite your second number: ";
	int num_2{ get_int_from_user() };

	std::cout << '\n' << num_1 << " + " << num_2 << " is " << num_1 + num_2
			  << '\n' << num_1 << " - " << num_2 << " is " << num_1 - num_2;
}
void doubled_num()
{
	std::cout << "Write number that you wanna doubled: ";

	int num{ get_int_from_user() };

	std::cout << "\nDoubled number of "<< num << " is " << num * 2 ;
}
void division_num()
{
	std::cout << "Write first number for division: ";
	int num1 = get_int_from_user();
	std::cout << "\nWrite second number for division: ";
	int num2 = get_int_from_user();
	std::cout << "\nResult " << num1 << " / " << num2 << " = " << num1 / num2;
}
void larger_and_smaller_numbers()
{
	std::cout << "Enter an integer 1: ";
	int num1{ get_int_from_user() };

	std::cout << "\nEnter an integer 2: ";
	int num2{ get_int_from_user() };

	std::cout << "\nThe larger value is " << ( (num1 > num2) ? num1 : num2);
	std::cout << "\n\nThe smaller value is " << ( (num1 < num2) ? num1 : num2);

}
int main()
{
	std::cout << "Welcome to sykaax console app version 1.0.0\n";
	auto myArray2{ std::to_array<int>({ 9, 7, 5, 3, 1 }) };
	bool status_exit{false};
	int user_command{};

	while ( status_exit != true)
	{
		std::cout << "\nWrite number of function to start that function or '1' for help, or '0' for exit: ";

		user_command = get_int_from_user();

		switch (user_command)
		{
			case 1:
				std::cout << "\nWrite special number for start that functions:"
					      << "\n2 - plus_minus_num"
						  << "\n3 - larger_and_smaller_numbers"
					      << "\n4 - doubled_num"
					      << "\n5 - division_num" 
						  << "\n6 - plus_minus_double"
					      << "\n7 - invest_counter"
						  << "\n8 - even_or_odd_int"
					      << "\n9 - time_of_name"
						  << "\n10 - memory_cheat"
						  << "\n11 - calculate_two_float_num"
					      << "\n12 - ball_falls_from_the_tower"
					      << "\n13 - bits8_rotate_left"
						  << "\n14 - generate_of_monsters"
						  << "\n15 - sort_my_names"
					      << "\n16 - point3d"
						  << "\n17 - points_distance"
						  << "\n0 - for exit\n";
				break;
			case 2:
				start_func("plus_minus_num");
				plus_minus_num();
				finish_func("plus_minus_num");
				break;
			case 3:
				start_func("larger_and_smaller_numbers");
				larger_and_smaller_numbers();
				finish_func("larger_and_smaller_numbers");
				break;
			case 4:
				start_func("doubled_num");
				doubled_num();
				finish_func("doubled_num");
				break;
			case 5:
				start_func("division_num");
				division_num();
				finish_func("division_num");
				break;
			case 6:
				start_func("plus_minus_double");
				plus_minus_double();
				finish_func("plus_minus_double");
				break;
			case 7:
				start_func("invest_counter");
				invest_counter();
				finish_func("invest_counter");
				break;
			case 8:
				start_func("even_or_odd_int");
				even_or_odd_int();
				finish_func("even_or_odd_int");
				break;
			case 9:
				start_func("time_of_name");
				time_of_name();
				finish_func("time_of_name");
				break;
			case 10:
				start_func("memory_cheat");
				memory_cheat();
				finish_func("memory_cheat");
				break;
			case 11:
				start_func("calculate_two_float_num");
				calculate_two_float_num();
				finish_func("calculate_two_float_num");
				break;
			case 12:
				start_func("ball_falls_from_the_tower");
				ball_falls_from_the_tower();
				finish_func("ball_falls_from_the_tower");
				break;
			case 13:
				start_func("bits8_rotate_left");
				bits8_rotate_left();
				finish_func("bits8_rotate_left");
				break;
			case 14:
				start_func("generate_of_monsters");
				generate_of_monsters::generate_of_monsters();
				finish_func("generate_of_monsters");
				break;
			case 15:
				start_func("sort_my_names");
				sort_my_names::sort_my_names();
				finish_func("sort_my_names");
				break;
			case 16:
				start_func("point3d");
				point3d::point3d();
				finish_func("point3d");
				break;
			case 17:
				start_func("points_distance");
				points_distance::points_distance();
				finish_func("points_distance");
				break;
			case 0:
				status_exit = true;
				break;
		}
	}

	
	return 0;
}
