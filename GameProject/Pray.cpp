#include "Pray.h"


Pray::Pray(int _map_width, int _map_height)
{
	map_width = _map_width;
	map_height = _map_height;

	pray_position.at(0) = int(rand() % (map_width - 10));
	pray_position.at(1) = int(rand() % (map_height - 10));

}

void Pray::make_step()
{
	if (int(rand() % 100) > 50)
	{
		if ((pray_position.at(0) + 1) < map_width)
		{
			pray_position.at(0) += 1;
		}
		
		else
		{
			pray_position.at(0) = 0;
		}
		
	}

	else
	{
		if ((pray_position.at(0) + 1) > 0)
		{
			pray_position.at(0) -= 1;
		}

		else
		{
			pray_position.at(0) = map_width;
		}
	}

	if (int(rand() % 100) > 50)
	{
		if ((pray_position.at(1) + 1) < map_height)
		{
			pray_position.at(1) += 1;
		}

		else
		{
			pray_position.at(1) = 0;
		}

	}

	else
	{
		if ((pray_position.at(1) - 1) > 0)
		{
			pray_position.at(1) -= 1;
		}

		else
		{
			pray_position.at(1) = map_height;
		}
	}
	
}

std::vector<int> Pray::get_pray_position()
{
	return pray_position;
}

void Pray::set_pray_position(std::vector<int> position)
{
	pray_position.at(0) = position.at(0);
	pray_position.at(1) = position.at(1);
}