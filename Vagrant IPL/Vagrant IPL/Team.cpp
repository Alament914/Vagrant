#include "Team.h"

Team::Team(string name, int points, Result* lastNMatches)
{
	SetData(name, points, lastNMatches);
}

void Team::SetData(string name, int points, Result* lastNMatches)
{
	this->name = name;
	this->points = points;
	this->lastNMatches = new Result[Team::N];
	for (int i = 0; i < Team::N; ++i)
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
		cout << "\nResult of Last " << Team::N << " Matches :\n\t";
	}
	for (int i = 0; i < Team::N; ++i)
	{
		cout << (lastNMatches[i] == Result::Loss ? "Loss " : lastNMatches[i] == Result::Win ? "Win " : "Draw ");
	}
	cout << endl;
}

bool Team::HasNConsecutiveResults(int n, Result result)
{
	if (n > Team::N) return false;
	int curStreak = 0;
	for (int i = 0; i < Team::N; ++i)
	{
		curStreak = (lastNMatches[i] == result) ? curStreak + 1 : 0;
		if (curStreak == n) return true;
	}
	return false;
}

Team::~Team()
{
	delete[] lastNMatches;
}
