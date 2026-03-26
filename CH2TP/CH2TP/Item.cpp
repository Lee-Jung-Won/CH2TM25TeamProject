#include "Item.h"

int GetRankPriority(const string& rank)
{
	if (rank == "Normal")
	{
		return 1;
	}
	else if (rank == "Rare")
	{
		return 2;
	}
	else if (rank == "Epic")
	{
		return 3;
	}
	else if (rank == "Plastic")
	{
		return 4;
	}
	else if (rank == "Silver")
	{
		return 5;
	}
	else if (rank == "Gold")
	{
		return 6;
	}
	else if (rank == "Platinum")
	{
		return 7;
	}
	else if (rank == "Diamond")
	{
		return 8;
	}
}
