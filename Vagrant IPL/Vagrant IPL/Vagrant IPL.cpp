#include <iostream>
#include "Team.h"

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Team* teams = new Team[n];
		for (int i = 0; i < n; ++i)
		{
			string name;
			int points;
			Result* lastNMatches = new Result[5]();
			cin >> name;
			cin >> points;
			for (int j = 0; j < 5; ++j)
			{
				int result;
				cin >> result;
				lastNMatches[j] = result < 0 ? Result::Loss : result > 0 ? Result::Win : Result::Draw;
			}
			teams[i].SetData(name, points, lastNMatches);
			delete[] lastNMatches;
		}
		while (n--)
		{
			teams[n].ShowData();
			cout << endl;
		}
		delete[] teams;
	}
	return 0;
}