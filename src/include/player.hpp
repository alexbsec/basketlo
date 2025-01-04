#ifndef _BASKTLO_PLAYER_HPP
#define _BASKTLO_PLAYER_HPP

#include "entity.hpp"
#include "input.hpp"
#include "resource_holder.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using string = std::string;

class Player : public Entity { // Inherits indirectly SceneNode
public:
  enum Type { Archer, Mage, Warrior };

  explicit Player(Type type, const TextureHolder &textures);
  virtual void DrawCurrent(sf::RenderTarget &target,
                           sf::RenderStates states) const;

  sf::Sprite GetSprite() const;

  void SetMovementMap(const umap<Moving, bool> &map);
  void HandleMovement();

private:
  void HandleAnimation();

  sf::Vector2f _mPosition;
  sf::Sprite _mSprite;

  Type _mType;

  umap<Moving, bool> _movementMap;

  bool _mIsMoving;
  size_t _currentFrame = 0; // Current frame index
  sf::Time _deltaTime;
};

#endif
