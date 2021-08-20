#include "Deck.h"

#include <random>
#include <algorithm>

#include "GenericPlayer.h"


Deck::Deck()
{
	Populate();
	Shuffle();
	std::cout << m_cards.size() << std::endl;
	for (const auto& card : m_cards)
		std::cout << *card.get() << " ";
	std::cout << std::endl;
}

template<typename T, typename ... Ts>
void AddCards(T& hand, Ts ... ts)
{
	(hand.Add(ts, card::Suit::Clubs), ...);
	(hand.Add(ts, card::Suit::Diamonds), ...);
	(hand.Add(ts, card::Suit::Hearts), ...);
	(hand.Add(ts, card::Suit::Spades), ...);
}

void Deck::Populate()
{
	using namespace card;
	AddCards(*this, Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five,
		Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten,
		Rank::Jack, Rank::Queen, Rank::King);
}

void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(m_cards.begin(), m_cards.end(), g);
}

void Deck::Deal(Hand& hand)
{
	hand.Add(std::move(m_cards.back()));
	m_cards.pop_back();
	std::cout << m_cards.size() << std::endl;
	for (const auto& card : m_cards)
		std::cout << *card.get() << " ";
	std::cout << std::endl;
}

void Deck::AdditionalCards(GenericPlayer& player)
{
	while (player.IsHitting())
	{
		Deal(player);
		if (player.IsBoosted())
		{
			player.Bust();
			return;
		}
	}
}
