#include "include/entity.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

void Entity::Draw(sf::RenderWindow &window, sf::Sprite sprite) {
  window.draw(sprite);
}

void Entity::SetVelocity(sf::Vector2f velocity) { _mVelocity = velocity; }

void Entity::SetVelocity(float vx, float vy) {
  _mVelocity = sf::Vector2f(vx, vy);
}

void Entity::SetIsMoving(bool isMoving) { _mIsMoving = isMoving; }

void Entity::SetIsAlive(bool isAlive) { _mIsAlive = isAlive; }

void Entity::SetIsAttacking(bool isAttacking) { _mIsAttacking = isAttacking; }

sf::Vector2f Entity::GetVelocity() const { return _mVelocity; }

bool Entity::IsMoving() const { return _mIsMoving; }

bool Entity::IsAlive() const { return _mIsAlive; }

bool Entity::IsAttacking() const { return _mIsAttacking; }
