#pragma once

#include <string>
#include "CardModel.h"
#include "CardEnums.h"

CardEnums::CardNumber CardModel::GetCardNumber()
{
	return cardNumber;
}

CardEnums::Suit CardModel::GetSuit()
{
	return suit;
}

void CardModel::SetCardNumber(CardEnums::CardNumber number)
{
	cardNumber = number;
}

void CardModel::SetSuit(CardEnums::Suit s)
{
	suit = s;
}