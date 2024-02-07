#pragma once

#include "PlayerModel.h"
#include <string>
#include <list>

std::string PlayerModel::GetName()
{
	return name;
}

void PlayerModel::SetName(std::string name)
{
	this->name = name;
}

int PlayerModel::GetPlayer()
{
	return player;
}

void PlayerModel::SetPlayer(int player)
{
	this->player = player;
}

std::list<CardModel> PlayerModel::GetHand()
{
	return hand;
}

void PlayerModel::SetHand(std::list<CardModel> hand)
{
	this->hand = hand;
}