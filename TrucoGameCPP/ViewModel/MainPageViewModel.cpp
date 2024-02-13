#include "MainPageViewModel.h"
#include "../Model/CardModel.h"
#include "../Model/CardEnums.h"
#include <string>
#include <vector>
#include <random>

MainPageViewModel::MainPageViewModel(){}

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

std::string MainPageViewModel::TranslateCardIntoImageName(CardModel card)
{
    std::string ret = "./Assets/";
    switch (card.GetCardNumber())
    {
    case CardEnums::Four:
        ret += "4";
        break;
    case CardEnums::Five:
        ret += "5";
        break;
    case CardEnums::Six:
        ret += "6";
        break;
    case CardEnums::Seven:
        ret += "7";
        break;
    case CardEnums::Queen:
        ret += "Q";
        break;
    case CardEnums::Jack:
        ret += "J";
        break;
    case CardEnums::King:
        ret += "K";
        break;
    case CardEnums::Ace:
        ret += "A";
        break;
    case CardEnums::Two:
        ret += "2";
        break;
    case CardEnums::Three:
        ret += "3";
        break;
    }

    ret += "_";
    switch (card.GetSuit()) {
    case CardEnums::Diamonds:
        ret += "ouro";
        break;
    case CardEnums::Spades:
        ret += "espadas";
        break;
    case CardEnums::Hearts:
        ret += "copa";
        break;
    case CardEnums::Clubs:
        ret += "paus";
        break;
    }

    ret += ".png";
    return ret;
}

PlayerModel MainPageViewModel::GetP1()
{
	return player1;
}

PlayerModel MainPageViewModel::GetP2()
{
	return player2;
}

bool MainPageViewModel::isManilla(CardModel card, CardModel manilla)
{
    if (manilla.GetCardNumber() - card.GetCardNumber() == -1 || manilla.GetCardNumber() - card.GetCardNumber() == 9)
        return true;

    return false;
}

int MainPageViewModel::Player1WonTheRound(CardModel p1Card, CardModel p2Card, CardModel manilla)
{
    bool p1HasManilla, p2HasManilla;
    p1HasManilla = isManilla(p1Card, manilla);
    p2HasManilla = isManilla(p2Card, manilla);
    int p1CardNumber = p1Card.GetCardNumber();
    int p2CardNumber = p2Card.GetCardNumber();

    if (!p1HasManilla && !p2HasManilla)
    {
        if (p1CardNumber > p2CardNumber)
            return 1;
        else if (p1CardNumber < p2CardNumber)
            return -1;
        else if (p1CardNumber == p2CardNumber)
            return 0;
    }
    else if (p1HasManilla && !p2HasManilla)
    {
        return 1;
    }
    else if (!p1HasManilla && p2HasManilla)
    {
        return -1;
    }
    else
    {
        if (p1Card.GetSuit() > p2Card.GetSuit())
            return 1;
        else
            return -1;
    }
}

void MainPageViewModel::Dispose()
{
    deck.cards.clear();
}
