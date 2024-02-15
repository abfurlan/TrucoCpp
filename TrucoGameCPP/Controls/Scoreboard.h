#pragma once

class Scoreboard
{
public:
	Scoreboard();
	int GetP1Round();
	int GetP1TotalPoints();
	int GetP2Round();
	int GetP2TotalPoints();
	void SetTotalPoints(int winningPlayer, int earnedPoints);
	void SetRounds(int winningPlayer, int roundValue);

private:
	int p1Rounds;
	int p2Rounds;
	int p1TotalPoints;
	int p2TotalPoints;
};