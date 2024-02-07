#pragma once

#include <string>
#include <list>

class PlayerModel
{
	std::string name;
	int player;
	std::list<std::string> hand;

	std::string getName()
	{
		return name;
	}

	void setName(std::string name)
	{
		this->name = name;
	}

	int getPlayer()
	{
		return player;
	}

	void setPlayer(int player)
	{
		this->player = player;
	}

	std::list<std::string> getHand() 
	{
		return hand;
	}

	void setHand(std::list<std::string> hand)
	{
		this->hand = hand;
	}
};