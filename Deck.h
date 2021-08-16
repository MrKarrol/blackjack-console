#pragma once

#include "Hand.h"

class GenericPlayer;


class Deck : public Hand
{
public:
	Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand&);
	void AdditionalCards(GenericPlayer&);

};

