#pragma once

class Scoreboard
{
public:
	Scoreboard();
	void setRound(int round);
	int getRound();
	void setTotalPoints(int totalPoints);
	int getTotalPoints();

private:
	int round;
	int totalPoints;
};