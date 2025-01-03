#include "include/input.hpp"

InputManager::InputManager(sf::Event &event) : _mEvent(event) {
  _movementMap[Moving::UP] = false;
  _movementMap[Moving::DOWN] = false;
  _movementMap[Moving::LEFT] = false;
  _movementMap[Moving::RIGHT] = false;
}

umap<Moving, bool> InputManager::GetMovementInput() {
  AccessEvent();
  return _movementMap;
}

void InputManager::AccessEvent() {
  switch (_mEvent.type) {
  case sf::Event::KeyPressed: {
    HandlePlayerInput(_mEvent.key.code, true);
    break;
  }

  case sf::Event::KeyReleased: {
    HandlePlayerInput(_mEvent.key.code, false);
    break;
  }

  default:
    break;
  }
}

void InputManager::HandlePlayerInput(sf::Keyboard::Key keyCode,
                                     bool isPressed) {
  if (keyCode == sf::Keyboard::Key::W) {
    _movementMap[Moving::UP] = isPressed;
  }

  if (keyCode == sf::Keyboard::Key::S) {
    _movementMap[Moving::DOWN] = isPressed;
  }

  if (keyCode == sf::Keyboard::Key::A) {
    _movementMap[Moving::LEFT] = isPressed;
  }

  if (keyCode == sf::Keyboard::Key::D) {
    _movementMap[Moving::RIGHT] = isPressed;
  }
}
