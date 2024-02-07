#pragma once
#include "CardModel.h"
#include <string>
#include <list>

class PlayerModel
{
public:
	PlayerModel() {}
	std::string PlayerModel::GetName();
	int PlayerModel::GetPlayer();
	std::list<CardModel> PlayerModel::GetHand();
	void PlayerModel::SetName(std::string name);
	void PlayerModel::SetPlayer(int player);
	void PlayerModel::SetHand(std::list<CardModel> hand);

private:
	std::string name;
	int player;
	std::list<CardModel> hand;
};