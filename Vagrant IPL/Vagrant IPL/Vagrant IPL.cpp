#include <iostream>
#include "Team.h"

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, nTWS = 0;
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
			if (teams[i].Has2ConsecutiveLosses())
			{
				teamsWithStreak[nTWS] = &(teams[i]);
				nTWS++;
			}
			delete[] lastNMatches;
		}
		while (nTWS--)
		{
			teamsWithStreak[nTWS]->ShowData();
			cout << endl;
		}
		delete[] teamsWithStreak;
		delete[] teams;
	}
	return 0;
}