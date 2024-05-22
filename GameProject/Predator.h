#pragma once
#include<vector>
class Predator
{
private:

	std::vector<int> predator_position{0, 0};
	int predator_points;

	int map_width;
	int map_height;

public:

	Predator(int, int);
	void make_step(bool, bool, bool, bool);
	std::vector<int> get_predator_position();
	int get_predator_points();
	void set_predator_points(int);
	void set_predator_position(std::vector<int>);

};

