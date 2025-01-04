#ifndef _BASKTLO_GAME_HPP
#define _BASKTLO_GAME_HPP

#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <string>

using string = std::string;

class Game {
public:
  Game(const string &title);
  void Run();

private:
  void Update();
  void Render();
  void FixedTimeUpdate();

  sf::RenderWindow _mWindow;
  sf::Clock _mClock;
  sf::Time _deltaTime;
  std::unique_ptr<World> _mWorld;
};

#endif
