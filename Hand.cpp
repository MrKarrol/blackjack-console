#include "Hand.h"

#include "Card.h"


Hand::~Hand()
{
}

void Hand::Add(std::unique_ptr<Card> card)
{
	m_cards.emplace_back(std::move(card));
}

void Hand::Add(card::Rank rank, card::Suit suit, bool is_face_down)
{
	m_cards.emplace_back(std::make_unique<Card>(rank, suit, is_face_down));
}

void Hand::Clear()
{
	m_cards.clear();
}

int Hand::GetValue() const noexcept
{
	using namespace card;
	int total_sum = 0;
	int aces_count = 0;
	for (const auto & card : m_cards)
	{
		total_sum += card->GetValue();
		if (card->GetValue() == 11)
			++aces_count;
	}
	if (total_sum >= 21)
		total_sum -= aces_count * 10;
	return total_sum;
}
