#include "include/player.hpp"
#include "include/constants.hpp"
#include "include/resource_holder.hpp"
#include "include/utils.hpp"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>

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

sf::Sprite Player::GetSprite() const {
  return _mSprite;
}

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

  velocity =
      consts::PLAYER_SPEED * utils::TIME_PER_FRAME.asSeconds() * velocity;

  SetVelocity(velocity);

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
