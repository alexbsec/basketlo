#ifndef _BASKTLO_INPUT_HPP
#define _BASKTLO_INPUT_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>

template <typename T, typename Q> using umap = std::unordered_map<T, Q>;

enum class Moving { UP, DOWN, LEFT, RIGHT };

class InputManager {
public:
  InputManager(sf::Event &event);
  umap<Moving, bool> GetMovementInput();

private:
  void AccessEvent();
  void HandlePlayerInput(sf::Keyboard::Key keyCode, bool isPressed);

  sf::Event &_mEvent;
  umap<Moving, bool> _movementMap;
};

#endif
