#include "include/game.hpp"
#include "include/resource_holder.hpp"
#include "include/utils.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cmath>

const string PLAYER_ASSET_PATH = "./assets/characters/1/D_Idle.png";

Game::Game(const string &title)
    : _mWindow(sf::RenderWindow(
          sf::VideoMode(utils::WINDOW_WIDTH, utils::WINDOW_HEIGHT), title)) {
  _mWorld = std::make_unique<World>(_mWindow);
}

void Game::Run() {
  _deltaTime = sf::Time::Zero;
  while (_mWindow.isOpen()) {
    FixedTimeUpdate();
    Render();
  }
}

void Game::Update() { _mWorld->Update(_deltaTime); }

void Game::Render() {
  _mWindow.clear();
  _mWorld->Draw();

  _mWindow.setView(_mWindow.getDefaultView());
  _mWindow.display();
}

void Game::FixedTimeUpdate() {
  _mWorld->ProcessEvents();
  _deltaTime += _mClock.restart();
  while (_deltaTime > utils::TIME_PER_FRAME) {
    _deltaTime -= utils::TIME_PER_FRAME;
    Update();
  }
}
