#ifndef _BASKTLO_PLAYER_HPP
#define _BASKTLO_PLAYER_HPP

#include "entity.hpp"
#include "input.hpp"
#include "resource_holder.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using string = std::string;

class Player : public Entity {
public:
  enum Type { Archer, Mage, Warrior };

  enum AnimationState { Idle, Walking, Attacking, Dying };

  explicit Player(Type type);
  void Update(sf::Time deltaTime);

  sf::Sprite GetSprite() const;
  sf::Vector2f GetPosition() const;

  void SetMovementMap(const umap<Moving, bool> &map);

private:
  void HandleMovement();
  void HandleAnimation();

  sf::Vector2f _mPosition;
  sf::Sprite _mSprite;

  ResourceHolder<sf::Texture, textures::PlayerTexture> _mTextureResource;

  Type _mType;

  const float PLAYER_SPEED = 200.0f;

  umap<Moving, bool> _movementMap;

  bool _mIsMoving;
  size_t _currentFrame = 0; // Current frame index
  sf::Time _deltaTime;
};

#endif
