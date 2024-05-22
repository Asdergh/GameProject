#include "GameMap.h"


GameMap::GameMap(int _map_width, int _map_height)
{
	map_width = _map_width;
	map_height = _map_height;
	
	std::vector<char> char_row(map_width, ' ');
	map.resize(map_height, char_row);

	for (int map_i = 0; map_i < map_height; map_i++)
	{
		for (int map_j = 0; map_j < map_width; map_j++)
		{
			map[map_i][map_j] = ' ';
		}
	}

	
}

void GameMap::cheak_key_pressed()
{
	if (GetKeyState('w') & 0x8000)
	{
		W_pressed = true;
	}

	if (GetKeyState('s') & 0x8000)
	{
		S_pressed = true;
	}

	if (GetKeyState('a') & 0x8000)
	{
		A_pressed = true;
	}

	if (GetKeyState('d') & 0x8000)
	{
		D_pressed = true;
	}
}

void GameMap::run_game()
{

	Predator predator_object(map_width, map_height);
	Pray pray_object(map_width, map_height);
	int curent_points = 0;

	std::vector<int> predator_position = predator_object.get_predator_position();
	std::vector<int> pray_position = pray_object.get_pray_position();
	std::vector<int> predator_past_position{ 0, 0 };
	std::vector<int> pray_past_position{ 0, 0 };

	int test_iteration = 0;
	while (true)
	{

		if (curent_points == 10)
		{
			break;
		}

		if (predator_position.at(0) == pray_position.at(0) and predator_position.at(1) == pray_position.at(1))
		{
			curent_points += 1;
			
			std::vector<int> new_pred_cores{ int(rand() % map_width), int(rand() % map_height) };
			std::vector<int> new_pray_cores{ int(rand() % map_width), int(rand() % map_height) };

			predator_object.set_predator_position(new_pred_cores);
			pray_object.set_pray_position(new_pray_cores);

		}
		
		W_pressed = false;
		S_pressed = false;
		A_pressed = false;
		D_pressed = false;

		cheak_key_pressed();
		predator_object.make_step(W_pressed, S_pressed, A_pressed, D_pressed);
		pray_object.make_step();

		predator_position = predator_object.get_predator_position();
		pray_position = pray_object.get_pray_position();

		map[predator_past_position.at(0)][predator_past_position.at(1)] = ' ';
		map[pray_past_position.at(0)][pray_past_position.at(1)] = ' ';

		map[predator_position.at(0)][predator_position.at(1)] = '@';
		map[pray_position.at(0)][pray_position.at(1)] = '$';

		

		
		for (int map_i = 0; map_i < map_width; map_i++)
		{
			for (int map_j = 0; map_j < map_height; map_j++)
			{
				std::cout << map[map_i][map_j];
			}
		}
		predator_past_position = predator_object.get_predator_position();
		pray_past_position = pray_object.get_pray_position();
		test_iteration += 1;
	}
	
}