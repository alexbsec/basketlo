#include "include/player.hpp"
#include "include/resource_holder.hpp"
#include "include/utils.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

const string PLAYER_ASSET_PATH = "./assets/characters/1/D_Idle.png";

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

Player::Player(Type type) : _mPosition(), _mSprite(), _mType(type), _mIsMoving(false) {
  unsigned int textureCount = 0;
  for (const auto& playerTexture : textures::PLAYER_TEXTURES) {
    _mTextureResource.Load(playerTexture, PLAYER_ASSET_PATH,
            sf::IntRect(X_START + textureCount * X_OFFSET, Y_START, X_PIXELS, Y_PIXELS));
    textureCount++;
  }
  _mSprite.setTexture(_mTextureResource.Get(textures::PlayerTexture::Idle1));
  _mSprite.setPosition(100.0f, 100.0f);
  _mSprite.setScale(X_SCALE, Y_SCALE);

  _movementMap[Moving::UP] = false;
  _movementMap[Moving::DOWN] = false;
  _movementMap[Moving::LEFT] = false;
  _movementMap[Moving::RIGHT] = false;
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
  // Set the texture for the current frame
  _mSprite.setTexture(_mTextureResource.Get(textures::PLAYER_TEXTURES[_currentFrame]));
}

