#pragma once
#include<vector>

class Pray
{
private:
	
	int map_width;
	int map_height;

	std::vector<int> pray_position{ 0, 0 };

public:
	
	Pray(int, int);
	void make_step();
	std::vector<int> get_pray_position();
	void set_pray_position(std::vector<int>);
};

