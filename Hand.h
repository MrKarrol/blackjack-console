#pragma once

#include <vector>
#include <memory>

#include "Card.h"


class Hand
{
public:
	~Hand();

	void Add(std::unique_ptr<Card>);
	void Add(card::Rank, card::Suit, bool is_face_down = false);
	void Clear();
	int GetValue() const noexcept;

protected:
	std::vector<std::unique_ptr<Card>> m_cards;

};

