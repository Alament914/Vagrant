#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Result { Loss = -1, Draw = 0, Win = 1 };

class Team {

	string name;
	int points;
	Result* lastNMatches;
public:
	Team() {}
	Team(string name, int points, Result* lastNMatches);
	void SetData(string name, int points, Result* lastNMatches);
	void ShowData(bool tableFormat = false);
	~Team();
};