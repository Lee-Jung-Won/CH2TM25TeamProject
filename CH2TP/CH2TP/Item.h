#pragma once
#include <string>

using namespace std;
class Character;

typedef struct Tname
{
	string name;
	string rank;
} Tn;

inline bool operator<(const Tn& a, const Tn& b)
{
	if (a.name == b.name)
	{
		return a.rank < b.rank;
	}
	return a.name < b.name;
}

inline bool operator==(const Tn& a, const Tn& b)
{
	return (a.name == b.name) && (a.rank == b.rank);
}

class Item
{
public:
	virtual const Tn& getName() const = 0;
	virtual void use(Character* chr) = 0;
	virtual int getstore() = 0;
	virtual void setstore(int newnum) = 0;
};

