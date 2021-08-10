#include "House.h"

#include "Card.h"


House::House()
    : GenericPlayer("Dealer")
{
}

bool House::IsHitting() const
{
    if (GetValue() <= 16)
        return true;
    return false;
}

void House::FlipFirstCard()
{
    if (m_cards.size())
        m_cards.at(0)->Flip();
}
