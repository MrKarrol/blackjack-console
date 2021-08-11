#include "GenericPlayer.h"

#include "Card.h"


GenericPlayer::GenericPlayer(const std::string& name)
    : m_name(name)
{
}

GenericPlayer::GenericPlayer(std::string&& name)
    : m_name(std::move(name))
{
}

bool GenericPlayer::IsBoosted() const
{
    return GetValue() > 21;
}

void GenericPlayer::Bust() const
{
    std::cout << "Player " << m_name << " busted. Total score: " << GetValue() << std::endl;
}

std::ostream& operator << (std::ostream& out, const GenericPlayer& player)
{
	out << "Player " << player.m_name << " has ";
	for (const auto& card : player.m_cards)
		out << *card.get() << " ";
	out << ". Total sum: " << player.GetValue();
	return out;
}
