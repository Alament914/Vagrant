#include <iostream>
#include "Team.h"

int getInitInput(int& streak, Result& streakResult)
{
	int nTestCases;
	string t;
	cin >> t;
	if (t == "input" || t == "Input" || t == "INPUT")
	{
		cin >> streak;
		cin >> t;
		if (t == "loss" || t == "LOSS" || t == "Loss")
		{
			streakResult = Result::Loss;
		}
		if (t == "win" || t == "WIN" || t == "Win")
		{
			streakResult = Result::Win;
		}
		if (t == "draw" || t == "DRAW" || t == "Draw")
		{
			streakResult = Result::Draw;
		}
		cin >> nTestCases;
	}
	else
	{
		nTestCases = stoi(t);
	}
	return nTestCases;
}

int main()
{
	int streak;
	Result streakResult;
	int t = getInitInput(streak, streakResult);
	while (t--)
	{
		int n, nTWS = 0;
		double pointsSum = 0;
		cin >> n;
		Team* teams = new Team[n];
		Team** teamsWithStreak = new Team * [n] {nullptr};
		for (int i = 0; i < n; ++i)
		{
			string name;
			int points;
			Result* lastNMatches = new Result[Team::N]();
			cin >> name;
			cin >> points;
			for (int j = 0; j < Team::N; ++j)
			{
				int result;
				cin >> result;
				lastNMatches[j] = result < 0 ? Result::Loss : result > 0 ? Result::Win : Result::Draw;
			}
			teams[i].SetData(name, points, lastNMatches);
			if (teams[i].HasNConsecutiveResults(streak, streakResult))
			{
				teamsWithStreak[nTWS] = &(teams[i]);
				nTWS++;
			}
			delete[] lastNMatches;
		}
		
		for(int i = 0; i < nTWS; ++i)
		{
			teamsWithStreak[i]->ShowData();
			pointsSum += teamsWithStreak[i]->getPoints();
			cout << endl;
		}
		cout << "\n\nAverage of Points scored by shortlisted teams = \t" << pointsSum / nTWS << "\n\n";
		delete[] teamsWithStreak;
		delete[] teams;
	}
	return 0;
}