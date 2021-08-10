#include <iostream>

#include <cassert>

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "House.h"


int main()
{
    // test 1
    {
        std::cout << "----- test 1 -----" << std::endl;
        {
            Card card(card::Rank::Ace, card::Suit::Clubs, true);
            std::cout << card << " ";
            card.Flip();
            std::cout << card << " ";
        }
        {
            Card card(card::Rank::Jack, card::Suit::Diamonds);
            std::cout << card << " ";
        }
        {
            Card card(card::Rank::Ten, card::Suit::Spades);
            std::cout << card << " ";
        }
        {
            Card card(card::Rank::Queen, card::Suit::Hearts);
            std::cout << card << " ";
        }
        {
            Card card(card::Rank::King, card::Suit::Diamonds);
            std::cout << card << std::endl;
        }
    }
    // test 2
    {
        std::cout << "----- test 2 -----" << std::endl;
        Player player("CoolJoker");
        player.Add(card::Rank::Ace, card::Suit::Spades);
        player.Add(card::Rank::Two, card::Suit::Hearts);
        std::cout << player << std::endl;
        if (player.IsHitting())
        {
            player.Add(card::Rank::Jack, card::Suit::Diamonds);
            std::cout << player << std::endl;
        }
        player.Win();
        player.Lose();
        player.Push();
    }
    // test 3
    {
        std::cout << "----- test 3 -----" << std::endl;
        House house;
        house.Add(card::Rank::Ace, card::Suit::Spades, true);
        house.Add(card::Rank::Two, card::Suit::Hearts);
        std::cout << house << std::endl;
        if (house.IsHitting())
        {
            house.Add(card::Rank::Jack, card::Suit::Diamonds);
            std::cout << house << std::endl;
        }
        house.FlipFirstCard();
        std::cout << house << std::endl;
    }

}
