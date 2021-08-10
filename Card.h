#pragma once

#include <string>
#include <iostream>

namespace card
{
	enum class Suit
	{
		NoSuit = 0,
		Spades,
		Hearts,
		Diamonds,
		Clubs
	};

	enum class Rank
	{
		NoRank = 0,
		Ace,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};
} // end of namespace card

class Card
{
public:
	Card(card::Rank rank, card::Suit suit, bool face_down = false);
	~Card();

	void Flip() noexcept;
	int GetValue() const noexcept;
	std::string ToString() const noexcept;
	friend std::ostream& operator <<(std::ostream& out, const Card& card);

private:
	card::Rank m_rank{ card::Rank::NoRank };
	card::Suit m_suit{ card::Suit::NoSuit };
	bool m_face_down{};

};

std::ostream& operator <<(std::ostream& out, const Card& card);