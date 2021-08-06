#include "Hand.h"

#include "Card.h"


void Hand::Add(std::shared_ptr<Card> card)
{
	m_cards.emplace_back(card);
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
	for (auto card : m_cards)
	{
		total_sum += card->GetValue();
		if (card->GetValue() == 11)
			++aces_count;
	}
	if (total_sum >= 21)
		total_sum -= aces_count * 10;
	return total_sum;
}
