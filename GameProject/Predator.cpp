#include "Predator.h"


Predator::Predator(int _map_width, int _map_height)
{
	map_width = _map_width;
	map_height = _map_height;

	predator_position.at(0) = rand() % (map_width - 10);
	predator_position.at(0) = rand() % (map_height - 10);
	predator_points = 0;
}

void Predator::make_step(bool W, bool S, bool A, bool D)
{
	if (W == true and A == true)
	{
		if ((predator_position.at(0) + 3) > map_width)
		{
			predator_position.at(0) = 0;
		}

		if ((predator_position.at(1) + 3) < 0)
		{
			predator_position.at(1) = map_height;
		}

		predator_position.at(0) += 3;
		predator_position.at(1) -= 3;
	}

	else if (W == true and D == true)
	{
		if ((predator_position.at(0) + 3) > map_width)
		{
			predator_position.at(0) = 0;
		}

		if ((predator_position.at(1) + 3) > map_height)
		{
			predator_position.at(1) = 0;
		}

		predator_position.at(0) += 3;
		predator_position.at(1) += 3;
	}

	else if (S == true and A == true)
	{
		if ((predator_position.at(0) + 3) < 0)
		{
			predator_position.at(0) = map_width;
		}

		if ((predator_position.at(1) + 3) < 0)
		{
			predator_position.at(1) = map_height;
		}

		predator_position.at(0) -= 3;
		predator_position.at(1) -= 3;
	}

	else if (S == true and D == true)
	{
		if ((predator_position.at(0) + 3) < 0)
		{
			predator_position.at(0) = 0;
		}

		if ((predator_position.at(1) + 3) > map_height)
		{
			predator_position.at(1) = 0;
		}

		predator_position.at(0) -= 3;
		predator_position.at(1) += 3;
	}

	else if (W == true)
	{
		if ((predator_position.at(0) + 3) > map_width)
		{
			predator_position.at(0) = 0;
		}

		predator_position.at(0) += 3;
	}

	else if (S == true)
	{
		if ((predator_position.at(0) + 3) < 0)
		{
			predator_position.at(0) = map_width;
		}

		predator_position.at(0) -= 3;
	}

	else if (A == true)
	{
		if ((predator_position.at(1) + 3) < 0)
		{
			predator_position.at(1) = 0;
		}

		predator_position.at(1) -= 3;
	}

	else if (D == true)
	{
		if ((predator_position.at(1) + 3) > map_height)
		{
			predator_position.at(1) = 0;
		}

		predator_position.at(1) += 3;
	}
}

std::vector<int> Predator::get_predator_position()
{
	return predator_position;
}

int Predator::get_predator_points()
{
	return predator_points;
}

void Predator::set_predator_points(int curent_points)
{
	predator_points = curent_points;
}

void Predator::set_predator_position(std::vector<int> position)
{
	predator_position.at(0) = position.at(0);
	predator_position.at(1) = position.at(1);
}