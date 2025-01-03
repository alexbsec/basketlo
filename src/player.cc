#include "include/player.hpp"
#include "include/resource_holder.hpp"
#include "include/utils.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>


// Start position of the Idle Sprite
const int X_START = 9; // 13;
const int Y_START = 3; // 18;

// Size of the int rectangle containing the sprite
const int X_PIXELS = 13;
const int Y_PIXELS = 18;

// Idle animation offset
const int X_OFFSET = 32;

// Player scaling
const float PLAYER_HEIGHT = 70.0f;
const float ASPECT_RATIO = (float)X_PIXELS / Y_PIXELS;
const float X_SCALE = (ASPECT_RATIO * PLAYER_HEIGHT) / X_PIXELS;
const float Y_SCALE = PLAYER_HEIGHT / Y_PIXELS;

textures::ID ToTextureID(Player::Type type) {
  switch (type) {
  case Player::Type::Archer: {
    return textures::ID::Archer;
  }

  case Player::Type::Mage: {
    return textures::ID::Mage;
  }

  case Player::Type::Warrior: {
    return textures::ID::Warrior;
  }
  }

  return textures::ID::None;
}

Player::Player(Type type, const TextureHolder &textures)
    : _mPosition(), _mSprite(textures.Get(ToTextureID(type))), _mType(type),
      _mIsMoving(false) {
  _movementMap[Moving::UP] = false;
  _movementMap[Moving::DOWN] = false;
  _movementMap[Moving::LEFT] = false;
  _movementMap[Moving::RIGHT] = false;

  sf::FloatRect spriteBounds = _mSprite.getLocalBounds();
  _mSprite.setOrigin(spriteBounds.width / 2.0f, spriteBounds.height / 2.0f);
}

void Player::DrawCurrent(sf::RenderTarget &target,
                         sf::RenderStates states) const {
  target.draw(_mSprite, states);
}

void Player::Update(sf::Time deltaTime) {
  _deltaTime = deltaTime;
  HandleMovement();
}

sf::Sprite Player::GetSprite() const { return _mSprite; }

sf::Vector2f Player::GetPosition() const { return _mPosition; }

void Player::SetMovementMap(const umap<Moving, bool> &map) {
  _movementMap = map;
}

void Player::HandleMovement() {
  float vx = 0.0f;
  float vy = 0.0f;

  if (_movementMap[Moving::UP]) {
    vy -= 1.0f;
  }

  if (_movementMap[Moving::DOWN]) {
    vy += 1.0f;
  }

  if (_movementMap[Moving::LEFT]) {
    vx -= 1.0f;
  }

  if (_movementMap[Moving::RIGHT]) {
    vx += 1.0f;
  }

  sf::Vector2f velocity(vx, vy);

  utils::NormalizeVector2f(velocity);

  velocity = PLAYER_SPEED * utils::TIME_PER_FRAME.asSeconds() * velocity;

  SetVelocity(velocity);
  _mSprite.move(velocity);

  if (utils::GetVector2fMaginitude(velocity) > 0.0f) {
    SetIsMoving(true);
  } else {
    SetIsMoving(false);
  }

  HandleAnimation();
}

void Player::HandleAnimation() {
  _currentFrame = (_currentFrame + 1) % textures::PLAYER_TEXTURES.size();
}
