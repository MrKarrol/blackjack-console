#include <iostream>

#include <cassert>

#include "Card.h"
#include "Hand.h"


int main()
{
    // test 1
    {
        Hand hand;
        hand.Add(std::make_unique<Card>(card::Rank::Nine, card::Suit::Diamonds));
        hand.Add(std::make_unique<Card>(card::Rank::Ace, card::Suit::Clubs));
        assert(hand.GetValue() == 20);
    }
    // test 2
    {
        Hand hand;
        hand.Add(std::make_unique<Card>(card::Rank::Ace, card::Suit::Clubs));
        hand.Add(std::make_unique<Card>(card::Rank::Nine, card::Suit::Diamonds));
        assert(hand.GetValue() == 20);
    }
    // task 3
    {
        Hand hand;
        hand.Add(std::make_unique<Card>(card::Rank::Ace, card::Suit::Diamonds));
        hand.Add(std::make_unique<Card>(card::Rank::Ten, card::Suit::Diamonds));
        assert(hand.GetValue() == 11);
    }
    // task 4
    {
        Hand hand;
        hand.Add(std::make_unique<Card>(card::Rank::Ten, card::Suit::Spades));
        hand.Add(std::make_unique<Card>(card::Rank::Ace, card::Suit::Hearts));
        assert(hand.GetValue() == 11);
    }
}
