#ifndef _BASKTLO_ENTITY_HPP
#define _BASKTLO_ENTITY_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class IMovableObject {
  public:
    ~IMovableObject() = default;
    virtual void Update() = 0;
    virtual sf::Sprite GetSprite() const = 0;
    virtual sf::Vector2f GetPosition() const = 0;
    virtual sf::Vector2f GetMovementVector() const = 0;
};

class Entity {
  public:
    void Draw(sf::RenderWindow& window, sf::Sprite sprite);
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
    bool _mIsMoving;
    bool _mIsAlive;
    bool _mIsAttacking;
    sf::Vector2f _mVelocity;
};

#endif
