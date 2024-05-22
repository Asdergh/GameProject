#pragma once
#include<iostream>
#include<vector>
#include<Windows.h>
#include"Pray.h"
#include"Predator.h"

class GameMap
{
private:

	bool W_pressed = false;
	bool S_pressed = false;
	bool A_pressed = false;
	bool D_pressed = false;

	int map_width;
	int map_height;
	

	std::vector<std::vector<char>> map;

public:

	GameMap(int, int);
	void cheak_key_pressed();
	void run_game();

};

