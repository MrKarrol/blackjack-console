#include "Card.h"


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

Card::~Card()
{
}

std::ostream& operator <<(std::ostream& out, const Card& card)
{
	if (card.m_face_down)
	{
		out << "XX";
		return out;
	}

	using namespace card;
	std::string card_string;
	switch (card.m_rank)
	{
	case Rank::Ace:
		card_string += "A";
		break;
	case Rank::Two:
		card_string += "2";
		break;
	case Rank::Three:
		card_string += "3";
		break;
	case Rank::Four:
		card_string += "4";
		break;
	case Rank::Five:
		card_string += "5";
		break;
	case Rank::Six:
		card_string += "6";
		break;
	case Rank::Seven:
		card_string += "7";
		break;
	case Rank::Eight:
		card_string += "8";
		break;
	case Rank::Nine:
		card_string += "9";
		break;
	case Rank::Ten:
		card_string += "10";
		break;
	case Rank::Jack:
		card_string += "J";
		break;
	case Rank::Queen:
		card_string += "Q";
		break;
	case Rank::King:
		card_string += "K";
		break;
	default:
		card_string += "ERROR";
	}

	switch (card.m_suit)
	{
	case Suit::Hearts:
		card_string += char(3);
		break;
	case Suit::Diamonds:
		card_string += char(4);
		break;
	case Suit::Clubs:
		card_string += char(5);
		break;
	case Suit::Spades:
		card_string += char(6);
		break;
	default:
		card_string += "ERROR";
	}
	out << card_string;
	return out;
}