#pragma once

#include <string>

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

	inline std::string SuitToString(Suit suit);

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

	inline std::string RankToString(Rank rank);

} // end of namespace card

class Card
{
public:
	Card(card::Rank rank, card::Suit suit, bool face_down = false);

	void Flip() noexcept;
	int GetValue() const noexcept;
	std::string ToString() const noexcept;

private:
	card::Rank m_rank{ card::Rank::NoRank };
	card::Suit m_suit{ card::Suit::NoSuit };
	bool m_face_down{};

};

