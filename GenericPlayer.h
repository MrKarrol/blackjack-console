#pragma once

#include "Hand.h"

#include <string>


class GenericPlayer : public Hand
{
public:
	explicit GenericPlayer(const std::string& name);
	explicit GenericPlayer(std::string&& name);

	virtual bool IsHitting() const = 0;
	bool IsBoosted() const;
	void Bust() const;

private:
	const std::string m_name;

};

