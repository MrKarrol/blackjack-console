#include "Game.h"

#include <iostream>


int main()
{
    bool wanna_play = false;
    {
        std::cout << "Hello here, in our casino! Here is blackjack table. Wanna play? [y/n]" << std::endl;
        char answer = 'n';
        std::cin >> answer;
        std::cin.ignore();
        switch (answer)
        {
        case 'y':
            wanna_play = true;
            break;
        default:
            break;
        }
    }
    
    if (wanna_play)
    {
        Game game({ "Mike" });

        game.play();

        bool to_continue = true;
        while (to_continue)
        {
            std::cout << "Do you want another play? [y/n]" << std::endl;
            char answer = 'n';
            std::cin >> answer;
            std::cin.ignore();
            switch (answer)
            {
            case 'y':
                system("cls");
                game.play();
                break;
            default:
                to_continue = false;
            }
        }
    }
    
    std::cout << "Thank you for playing in our casino. Welcome back anytime!!" << std::endl;
}
