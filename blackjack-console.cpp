#include "Player.h"
#include "House.h"
#include "Deck.h"


int main()
{
    Deck deck;
    Player player("Mike");
    deck.AdditionalCards(player);
}
