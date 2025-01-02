#include "include/game.hpp"
#include "include/utils.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cmath>

Game::Game(const string &title)
    : _mWindow(sf::RenderWindow(
          sf::VideoMode(utils::WINDOW_WIDTH, utils::WINDOW_HEIGHT), title)),
      _inputManager(nullptr),
      _mPlayer(std::make_unique<Player>(Player::Type::Archer)) {
  _movementMap[Moving::UP] = false;
  _movementMap[Moving::DOWN] = false;
  _movementMap[Moving::LEFT] = false;
  _movementMap[Moving::RIGHT] = false;
}

void Game::Run() {
  _deltaTime = sf::Time::Zero;
  while (_mWindow.isOpen()) {
    FixedTimeUpdate();
    Render();
  }
}

void Game::ProcessEvents() {
  sf::Event event;

  if (_inputManager == nullptr) {
    _inputManager = std::make_unique<InputManager>(event);
  }

  while (_mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      _mWindow.close();
    }
    _mPlayer->SetMovementMap(_inputManager->GetMovementInput());
  }
}

void Game::Update() { _mPlayer->Update(_deltaTime); }

void Game::Render() {
  _mWindow.clear();
  _mWindow.draw(_mPlayer->GetSprite());
  _mWindow.display();
}

void Game::FixedTimeUpdate() {
  ProcessEvents();
  _deltaTime += _mClock.restart();
  while (_deltaTime > utils::TIME_PER_FRAME) {
    _deltaTime -= utils::TIME_PER_FRAME;
    ProcessEvents();
    Update();
  }
}
