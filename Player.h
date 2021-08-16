#pragma once

#include "GenericPlayer.h"


class Player : public GenericPlayer
{
public:
	explicit Player(const std::string& name);
	explicit Player(std::string&& name);

	bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;

};

