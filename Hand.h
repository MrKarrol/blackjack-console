#pragma once

#include <vector>
#include <memory>


class Card;

class Hand
{
public:
	~Hand() = default;

	void Add(std::unique_ptr<Card>);
	void Clear();
	int GetValue() const noexcept;

private:
	std::vector<std::unique_ptr<Card>> m_cards;

};

