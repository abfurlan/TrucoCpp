#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
	this->p1Rounds = this->p2Rounds = 0;
	this->p1TotalPoints = this->p2TotalPoints = 0;
}

Scoreboard::GetP1Round()
{
	return round;
}

Scoreboard::GetP1TotalPoints()
{
	return totalPoints;
}

Scoreboard::GetP2Round()
{
	return round;
}

Scoreboard::GetP2TotalPoints()
{
	return totalPoints;
}

//here, round is the 3 rounds of which you must win 2 to get a point
Scoreboard::SetRounds(int winningPlayer, int roundValue)
{
	if (winningPlayer == 1)
		this->p1Rounds += 1;
	else
		this->p1Rounds += 1;

	if (this->p1Rounds == 2 || this->p2Rounds == 2)
	{
		this->p1Rounds = 0;
		this->p2Rounds = 0;
		if (this->p1Rounds == 2)
			this->SetTotalPoints(1, roundValue);
		else
			this->SetTotalPoints(2, roundValue);
	}
}

//and points are those of which you must win 12 to win a game
Scoreboard::SetTotalPoints(int winningPlayer, int earnedPoints)
{
	if (winningPlayer == 1)
		this->p1TotalPoints += earnedPoints;
	else
		this->p2TotalPoints += earnedPoints;
}