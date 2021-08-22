#pragma once

#include <memory>
#include <vector>
#include <string>

class Deck;
class House;
class Player;

class Game
{
public:
	explicit Game(const std::vector<std::string> &players_names);
	~Game();
	Game(const Game&) = default;
	Game(Game&&) = default;
	void play();

private:
	void ClearAll();
	bool AllBusted() const noexcept;

private:
	std::unique_ptr<Deck> m_deck = nullptr;
	std::unique_ptr<House> m_house = nullptr;
	std::vector<std::unique_ptr<Player>> m_players;

};

