#ifndef _BASKTLO_GAME_HPP
#define _BASKTLO_GAME_HPP

#include "input.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <string>
#include <unordered_map>

template <typename T, typename Q> using umap = std::unordered_map<T, Q>;

using string = std::string;

class Game {
public:
  Game(const string &title);
  void Run();

private:
  void ProcessEvents();
  void Update();
  void Render();
  void FixedTimeUpdate();

  sf::RenderWindow _mWindow;
  sf::Clock _mClock;
  sf::Time _deltaTime;
  umap<Moving, bool> _movementMap;
  std::unique_ptr<InputManager> _inputManager;
  std::unique_ptr<Player> _mPlayer;
};

#endif
