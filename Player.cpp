#include "Player.h"


Player::Player(const std::string& name)
    : GenericPlayer(name)
{
}

Player::Player(std::string&& name)
    : GenericPlayer(std::move(name))
{
}

bool Player::IsHitting() const
{
    while (true)
    {
        std::cout << "Do you want another card? [y/n]" << std::endl;
        char answer = 'n';
        std::cin >> answer;
        std::cin.ignore();
        switch (answer)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            continue;
        }
    }

    return false;
}

void Player::Win() const
{
    std::cout << "Player " << m_name << " wins!" << std::endl;
}

void Player::Lose() const
{
    std::cout << "Player " << m_name << " lose..." << std::endl;
}

void Player::Push() const
{
    std::cout << "Player " << m_name << " made push. " << std::endl;
}
