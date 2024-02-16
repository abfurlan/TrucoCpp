#pragma once
#include "CardEnums.h"

class CardModel
{
public:
	CardModel() {}

	CardEnums::CardNumber GetCardNumber();
	CardEnums::Suit GetSuit();
	void SetCardNumber(CardEnums::CardNumber number);
	void SetSuit(CardEnums::Suit s);
	bool operator == (const CardModel& c) const { return cardNumber == c.cardNumber && suit == c.suit; }
	bool operator != (const CardModel& c) const { return !operator==(c); }

private:
	CardEnums::CardNumber cardNumber;
	CardEnums::Suit suit;
};