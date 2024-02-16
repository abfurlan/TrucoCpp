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

int MainPageViewModel::GetManilla()
{
    return this->manilla;
}

void MainPageViewModel::SetManilla(int manillaNumber)
{
    this->manilla = manillaNumber;
}

bool MainPageViewModel::isManilla(CardModel card)
{
    if (manilla - card.GetCardNumber() == -1 || manilla - card.GetCardNumber() == 9)
        return true;

    return false;
}

int MainPageViewModel::Player1WonTheRound(CardModel p1Card, CardModel p2Card)
{
    bool p1HasManilla, p2HasManilla;
    p1HasManilla = isManilla(p1Card);
    p2HasManilla = isManilla(p2Card);
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

CardModel MainPageViewModel::BotPlayHighestCard()
{
    int highestCard = 0;
    CardModel ret;
    for (auto card : player2.GetHand())
    {
        if (isManilla(card))
        {
            if (highestCard > 0)
            {
                if (!isManilla(ret))
                {
                    ret = card;
                    highestCard = ret.GetCardNumber();
                }
                else
                {
                    if (card.GetSuit() > ret.GetSuit())
                    {
                        ret = card;
                        highestCard = ret.GetCardNumber();
                    }
                }
            }
            else
            {
                ret = card;
                highestCard = ret.GetCardNumber();
            }
        }
        else
        {
            if (highestCard > 0)
            {
                if (!isManilla(ret))
                {
                    if (card.GetCardNumber() > highestCard)
                    {
                        ret = card;
                        highestCard = ret.GetCardNumber();
                    }
                }
            }
            else
            {
                ret = card;
                highestCard = ret.GetCardNumber();
            }
        }
    }

    return ret;
}

CardModel MainPageViewModel::BotPlayLowestCard()
{
    int lowestCard = 11;
    CardModel ret;
    for (auto card : player2.GetHand())
    {
        if (!isManilla(card))
        {
            if (card.GetCardNumber() < lowestCard)
            {
                ret = card;
                lowestCard = ret.GetCardNumber();
            }
        }
        else
        {
            if (lowestCard < 11)
            {
                if (isManilla(ret))
                {
                    if (card.GetSuit() < ret.GetSuit())
                    {
                        ret = card;
                        lowestCard = ret.GetCardNumber();
                    }
                }
            }
            else
            {
                ret = card;
                lowestCard = ret.GetCardNumber();
            }
        }
    }

    return ret;
}

bool MainPageViewModel::BotHasManilla()
{
    for (auto card : player2.GetHand())
    {
        if (isManilla(card))
            return true;
    }

    return false;
}

bool MainPageViewModel::BotHasTwoManillas()
{
    int manillaCount = 0;
    for (auto card : player2.GetHand())
    {
        if (isManilla(card))
            manillaCount++;
    }

    if (manillaCount > 1)
        return true;
    else
        return false;
}

bool MainPageViewModel::BotHasZapOrHearts()
{
    for (auto card : player2.GetHand())
    {
        if (isManilla(card))
        {
            if (card.GetSuit() == CardEnums::Suit::Clubs || card.GetSuit() == CardEnums::Suit::Hearts)
                return true;
        }
    }

    return false;
}

//in this method, if bot has a higher card than yours, it returns 1; 0 if it has a card equals to yours and -1 if it has nothing
int MainPageViewModel::BotHasCardHigherThan(CardModel p1Card)
{
    int ret = -1;
    if (isManilla(p1Card))
    {
        for (auto card : player2.GetHand())
        {
            if (isManilla(card))
                if (card.GetSuit() > p1Card.GetSuit())
                    ret = 1;
        }
    }
    else
    {
        if (BotHasManilla())
            ret = 1;
        else
        {
            for (auto card : player2.GetHand())
            {
                if (card.GetCardNumber() > p1Card.GetCardNumber())
                    ret = 1;
                else if (card.GetCardNumber() == p1Card.GetCardNumber())
                    ret = 0;
            }
        }
    }

    return ret;
}

void MainPageViewModel::RemoveCardFromBotHand(CardModel playedCard)
{
    player2.RemoveCardFromHand(playedCard);
}



CardModel MainPageViewModel::BotPlayCard(int round, bool firstInRound, int botRounds)
{
    CardModel playedCard;
    if (firstInRound)
    {
        if (round == 1)
        {
            if (BotHasTwoManillas())
                playedCard = BotPlayLowestCard();
            else
                playedCard = BotPlayHighestCard();

            RemoveCardFromBotHand(playedCard);
        }
        else if (round == 2)
        {
            if (botRounds == 1 && BotHasZapOrHearts())
                playedCard = BotPlayLowestCard();
            else
                playedCard = BotPlayHighestCard();

            RemoveCardFromBotHand(playedCard);
        }
        else
        {
            playedCard = BotPlayHighestCard();
            RemoveCardFromBotHand(playedCard);
        }
    }
    else
    {
        if (round == 1)
        {
            if (BotHasTwoManillas())
                playedCard = BotPlayLowestCard();
            else
            {
                if (BotHasCardHigherThan(p1PlayedCard) > -1)
                    playedCard = BotPlayHighestCard();
                else
                    playedCard = BotPlayLowestCard();

            }

            RemoveCardFromBotHand(playedCard);
        }
        else if (round == 2)
        {
            playedCard = BotPlayHighestCard();
            RemoveCardFromBotHand(playedCard);
        }
        else
        {
            playedCard = BotPlayHighestCard();
            RemoveCardFromBotHand(playedCard);
        }
    }

    return playedCard;
}

float MainPageViewModel::CountBotCardsPower()
{
    float botTotalPoints = 0;
    for (auto card : player2.GetHand())
    {
        if (!isManilla(card))
            botTotalPoints += card.GetCardNumber();
    }

    return botTotalPoints;
}

bool MainPageViewModel::BotHasGoodHand(int round)
{
    float botTotalPoints = CountBotCardsPower();
    float acceptableCardsPower = 0;

    if (round == 1)
        acceptableCardsPower = 7;
    else if (round == 2)
        acceptableCardsPower = 9;
    else
        acceptableCardsPower = 8;

    if (BotHasManilla())
    {
        if (botTotalPoints >= acceptableCardsPower)
            return true;
        else
            return false;
    }
    else
    {
        if (botTotalPoints / player2.GetHand().size() > acceptableCardsPower)
            return true;
        else
            return false;
    }
}

//in this method, if bot wants to raise even more, it returns 1; 0 if it just accepts and -1 if it does not
int MainPageViewModel::BotAcceptTruco(int round, int botRounds)
{
    int ret;
    if (BotHasTwoManillas())
    {
        if (BotHasZapOrHearts())
            ret = 1;
        else
            ret = 0;
    }
    else
    {
        if (round == 1)
        {
            if (BotHasGoodHand(round))
                ret = 0;
            else
                ret = -1;
        }
        else if (round == 2)
        {
            if (botRounds > 0)
            {
                if (BotHasZapOrHearts())
                    ret = 1;
                else if (BotHasGoodHand(round))
                    ret = 0;
                else
                    ret = -1;
            }
            else
                ret = -1;
        }
        else
        {
            if (botRounds > 0)
            {
                if (BotHasZapOrHearts())
                    ret = 1;
                else if (BotHasGoodHand(round))
                    ret = 0;
                else
                    ret = -1;
            }
            else
                ret = -1;
        }
    }

    return ret;
}

void MainPageViewModel::Dispose()
{
    deck.cards.clear();
}
