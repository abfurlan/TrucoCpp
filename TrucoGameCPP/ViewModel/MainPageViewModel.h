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

	CardModel p1PlayedCard;

	MainPageViewModel();
	void InitializeDeck();
	void InitializePlayers();
	CardModel PickRandomCard();
	std::string TranslateCardIntoImageName(CardModel card);
	PlayerModel GetP1();
	PlayerModel GetP2();
	int GetManilla();
	void SetManilla(int manillaNumber);
	void Dispose();
	int Player1WonTheRound(CardModel p1Card, CardModel p2Card);
	CardModel BotPlayHighestCard();
	CardModel BotPlayLowestCard();
	bool BotHasManilla();
	bool BotHasTwoManillas();
	bool BotHasZapOrHearts();
	int BotHasCardHigherThan(CardModel p1Card);
	void RemoveCardFromBotHand(CardModel playedCard);
	CardModel BotPlayCard(int round, bool firstInRound, int botRounds);
	float CountBotCardsPower();
	bool BotHasGoodHand(int round);
	int BotAcceptTruco(int round, int botRounds);


private:
	Deck deck;
	PlayerModel player1;
	PlayerModel player2;
	int manilla;

	void DistributeCards();
	bool isManilla(CardModel card);
};