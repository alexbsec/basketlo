#ifndef _BASKTLO_ENTITY_HPP
#define _BASKTLO_ENTITY_HPP

#include "scene_node.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

class Entity : public SceneNode {
public:
  void SetVelocity(sf::Vector2f velocity);
  void SetVelocity(float vx, float vy);
  void SetIsMoving(bool isMoving);
  void SetIsAlive(bool isAlive);
  void SetIsAttacking(bool isAttacking);
  sf::Vector2f GetVelocity() const;
  bool IsMoving() const;
  bool IsAlive() const;
  bool IsAttacking() const;

private:
  virtual void UpdateCurrent(sf::Time deltaTime);
  
  bool _mIsMoving;
  bool _mIsAlive;
  bool _mIsAttacking;
  sf::Vector2f _mVelocity;
};

#endif
