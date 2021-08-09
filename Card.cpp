#include "Card.h"

#include <iostream>


Card::Card(card::Rank rank, card::Suit suit, bool face_down)
	: m_rank(rank)
	, m_suit(suit)
	, m_face_down(face_down)
{
}

void Card::Flip() noexcept
{
	m_face_down = !m_face_down;
}

int Card::GetValue() const noexcept
{
	using namespace card;
	switch (m_rank)
	{
	case Rank::Ace:
		return 11;
	case Rank::Two:
		return 2;
	case Rank::Three:
		return 3;
	case Rank::Four:
		return 4;
	case Rank::Five:
		return 5;
	case Rank::Six:
		return 6;
	case Rank::Seven:
		return 7;
	case Rank::Eight:
		return 8;
	case Rank::Nine:
		return 9;
	case Rank::Ten:
	case Rank::Jack:
	case Rank::Queen:
	case Rank::King:
		return 10;
	default:
		std::cerr << "ERROR in Card::GetValue()" << std::endl;
		return -1;
	}
}

std::string Card::ToString() const noexcept
{
	using namespace card;
	return RankToString(m_rank) + " of " + SuitToString(m_suit) + (m_face_down ? "(face down)" : "");
}

std::string card::SuitToString(Suit suit)
{
	switch (suit)
	{
	case Suit::Spades:
		return "Spades";
	case Suit::Hearts:
		return "Hearts";
	case Suit::Diamonds:
		return "Diamonds";
	case Suit::Clubs:
		return "Clubs";
	default:
		std::cerr << "ERROR in SuitToString" << std::endl;
		return "ERROR";
	}
}

std::string card::RankToString(Rank rank)
{
	switch (rank)
	{
	case Rank::Ace:
		return "Ace";
	case Rank::Two:
		return "Two";
	case Rank::Three:
		return "Three";
	case Rank::Four:
		return "Four";
	case Rank::Five:
		return "Five";
	case Rank::Six:
		return "Six";
	case Rank::Seven:
		return "Seven";
	case Rank::Eight:
		return "Eight";
	case Rank::Nine:
		return "Nine";
	case Rank::Ten:
		return "Ten";
	case Rank::Jack:
		return "Jack";
	case Rank::Queen:
		return "Queen";
	case Rank::King:
		return "King";
	default:
		std::cerr << "ERROR in RankToString" << std::endl;
		return "ERROR";
	}
}
