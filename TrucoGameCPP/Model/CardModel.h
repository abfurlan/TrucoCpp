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
	bool operator==(CardModel& card);

private:
	CardEnums::CardNumber cardNumber;
	CardEnums::Suit suit;
};