#include "Game.h"

#include "Deck.h"
#include "House.h"
#include "Player.h"


Game::Game(const std::vector<std::string> &players_names)
	: m_deck(std::make_unique<Deck>())
	, m_house(std::make_unique<House>())
{
	m_players.reserve(players_names.size());
	for (const auto& name : players_names)
		m_players.push_back(std::make_unique<Player>(name));

	m_deck->Shuffle();
}

Game::~Game() = default;

void Game::play()
{
	for (auto i = 0; i < 2; ++i)
	{
		for (auto& player : m_players)
			m_deck->Deal(*player);
		m_deck->Deal(*m_house);
	}
	m_house->FlipFirstCard();
	for (const auto& player : m_players)
		std::cout << *player << std::endl;
	std::cout << *m_house << std::endl;

	for (auto& player : m_players)
	{
		if (player->GetValue() == 21)
			continue;
		m_deck->AdditionalCards(*player);
	}

	m_house->FlipFirstCard();
	std::cout << *m_house << std::endl;

	if (AllBusted())
	{
		for (const auto& player : m_players)
			player->Lose();
		ClearAll();
		return;
	}

	if (m_house->GetValue() != 21)
		m_deck->AdditionalCards(*m_house);

	if (m_house->GetValue() == 21)
	{
		std::cout << *m_house << std::endl;
		std::cout << "Dealer made blackjack" << std::endl;
		for (const auto& player : m_players)
		{
			if (player->GetValue() != 21)
				player->Lose();
			else
				std::cout << "Player " << player->GetName() << " saved his bet." << std::endl;
		}

		ClearAll();
		return;
	}

	for (const auto& player : m_players)
	{
		if (player->GetValue() <= 21 and (player->GetValue() > m_house->GetValue() or m_house->GetValue() > 21))
			player->Win();
		else if (player->GetValue() <= 21 and player->GetValue() == m_house->GetValue())
			player->Push();
		else
			player->Lose();
	}
	ClearAll();
	m_deck->Populate();
	m_deck->Shuffle();
}

void Game::ClearAll()
{
	for (auto& player : m_players)
		player->Clear();
	m_house->Clear();
}

bool Game::AllBusted() const noexcept
{
	bool all_busted = true;
	for (const auto& player : m_players)
		if (not player->IsBoosted())
		{
			all_busted = false;
			break;
		}
	return all_busted;
}
