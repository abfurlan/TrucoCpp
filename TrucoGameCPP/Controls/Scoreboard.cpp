#include "Scoreboard.h"

Scoreboard::Scoreboard()
{

}

Scoreboard::setRound(int round)
{
	this->round = round;
}

Scoreboard::getRound()
{
	return round;
}

Scoreboard::setTotalPoints(int totalPoints)
{
	this->totalPoints = totalPoints;
}

Scoreboard::getTotalPoints()
{
	return totalPoints;
}