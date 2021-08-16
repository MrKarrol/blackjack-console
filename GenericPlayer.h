#pragma once

#include "Hand.h"

#include <string>
#include <iostream>


class GenericPlayer : public Hand
{
public:
	explicit GenericPlayer(const std::string& name);
	explicit GenericPlayer(std::string&& name);

	virtual bool IsHitting() const = 0;
	bool IsBoosted() const;
	void Bust() const;

	friend std::ostream& operator << (std::ostream& out, const GenericPlayer& player);

protected:
	const std::string m_name;

};

std::ostream& operator << (std::ostream& out, const GenericPlayer& player);
