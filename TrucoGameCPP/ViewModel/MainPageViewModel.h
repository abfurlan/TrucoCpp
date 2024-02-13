#pragma once

#include <string>
#include <vector>
#include "../Model/CardModel.h"
#include "../Model/PlayerModel.h"

class MainPageViewModel
{
public:
	struct Deck {
		std::vector<CardModel> cards;
	};

	MainPageViewModel();
	void InitializeDeck();
	void InitializePlayers();
	CardModel PickRandomCard();
	std::string TranslateCardIntoImageName(CardModel card);
	PlayerModel GetP1();
	PlayerModel GetP2();
	void Dispose();
	int Player1WonTheRound(CardModel p1Card, CardModel p2Card, CardModel manilla);

private:
	Deck deck;
	PlayerModel player1;
	PlayerModel player2;

	void DistributeCards();
	bool isManilla(CardModel card, CardModel manilla);
};