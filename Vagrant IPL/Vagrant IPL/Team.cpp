#include "Team.h"

Team::Team(string name, int points, Result* lastNMatches)
{
	SetData(name, points, lastNMatches);
}

void Team::SetData(string name, int points, Result* lastNMatches)
{
	this->name = name;
	this->points = points;
	this->lastNMatches = new Result[5];
	for (int i = 0; i < 5; ++i)
	{
		this->lastNMatches[i] = lastNMatches[i];
	}
}

void Team::ShowData(bool tableFormat)
{
	if (tableFormat)
	{
		cout << name << '\t' << points << '\t';
	}
	else
	{
		cout << "\nTeam Name :\t" << name;
		cout << "\nTeam Points :\t" << points;
		cout << "\nResult of Last 5 Matches :\n\t";
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << (lastNMatches[i] == Result::Loss ? "Loss " : lastNMatches[i] == Result::Win ? "Win " : "Draw ");
	}
	cout << endl;
}

Team::~Team()
{
	delete[] lastNMatches;
}
