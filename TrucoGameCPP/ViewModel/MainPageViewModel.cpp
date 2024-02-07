#include "MainPageViewModel.h"
#include "../Model/CardModel.h"
#include "../Model/CardEnums.h"
#include <string>
#include <vector>
#include <random>

MainPageViewModel::MainPageViewModel()
{

}

void MainPageViewModel::InitializeDeck()
{
	CardEnums::CardNumber cardNumbers[] = { CardEnums::CardNumber::Four, CardEnums::CardNumber::Five, CardEnums::CardNumber::Six, CardEnums::CardNumber::Seven
	, CardEnums::CardNumber::Queen , CardEnums::CardNumber::Jack , CardEnums::CardNumber::King , CardEnums::CardNumber::Ace , CardEnums::CardNumber::Two , CardEnums::CardNumber::Three };
	CardEnums::Suit cardSuits[] = { CardEnums::Suit::Diamonds, CardEnums::Suit::Spades, CardEnums::Suit::Hearts, CardEnums::Suit::Clubs };

	CardModel card;
	int index = 0;
	for (auto& i : cardNumbers)
	{
		for (auto& j : cardSuits)
		{
			card.SetCardNumber(i);
			card.SetSuit(j);
			deck.cards.insert(deck.cards.begin(), card);
		}
	}
}

void MainPageViewModel::InitializePlayers()
{
	player1.SetName("A");
	player2.SetName("B");
	player1.SetPlayer(1);
	player2.SetPlayer(2);
	DistributeCards();
}

CardModel MainPageViewModel::PickRandomCard()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, deck.cards.size());
	int randomCardIndex = distr(gen);
	//int randomCardIndex = rand() % deck.cards.size();
	CardModel card = deck.cards[randomCardIndex];
	//auto it = std::find(deck.cards.begin(), deck.cards.end(), randomCard);
	deck.cards.erase(deck.cards.end() - (deck.cards.size() - randomCardIndex));
	return card;
}

void MainPageViewModel::DistributeCards()
{
	std::list<CardModel> p1Hand;
	std::list<CardModel> p2Hand;
	for (int i = 0; i < 3; i++)
	{
		p1Hand.push_front(PickRandomCard());
	}

	for (int j = 0; j < 3; j++)
	{
		p2Hand.push_front(PickRandomCard());
	}

	player1.SetHand(p1Hand);
	player2.SetHand(p2Hand);

	p1Hand.clear();
	p2Hand.clear();
}

PlayerModel MainPageViewModel::GetP1()
{
	return player1;
}

PlayerModel MainPageViewModel::GetP2()
{
	return player2;
}

void MainPageViewModel::Dispose()
{
	deck.cards.clear();
}