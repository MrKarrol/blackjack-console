#pragma once

#include "GenericPlayer.h"


class House : public GenericPlayer
{
public:
	House();

	bool IsHitting() const;
	void FlipFirstCard();

};

