#include <iostream>

#include "Card.h"

int main()
{
    Card card(card::Rank::Ace, card::Suit::Spades);
    std::cout << "We have card " << card.ToString() << std::endl;
    card.Flip();
    std::cout << "Now we have card " << card.ToString() << std::endl;
    std::cout << "Value of this card is " << card.GetValue() << std::endl;
}
