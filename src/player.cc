#include "include/player.hpp"
#include "include/utils.hpp"

const string PLAYER_ASSET_PATH = "./assets/characters/1/D_Idle.png";

Player::Player() 
    : _mMovementVector()
    , _mPosition()
    , _mSprite() 
    , _mTexture() {
    if (!_mTexture.loadFromFile(PLAYER_ASSET_PATH)) {
       // Handle loading error
    }

    _mSprite.setTexture(_mTexture);
    _mSprite.setPosition(100.0f, 100.0f);

    _movementMap[Moving::UP] = false;
    _movementMap[Moving::DOWN] = false;
    _movementMap[Moving::LEFT] = false;
    _movementMap[Moving::RIGHT] = false;
}

void Player::Update() {
    _mMovementVector = sf::Vector2f(0.0f, 0.0f);
    
    if (_movementMap[Moving::UP]) {
        _mMovementVector.y -= 1.0f;
    }

    if (_movementMap[Moving::DOWN]) {
        _mMovementVector.y += 1.0f;
    }

    if (_movementMap[Moving::LEFT]) {
        _mMovementVector.x -= 1.0f;
    }

    if (_movementMap[Moving::RIGHT]) {
        _mMovementVector.x += 1.0f;
    }
    
    utils::NormalizeVector2f(_mMovementVector);

    _mMovementVector = PLAYER_SPEED * utils::TIME_PER_FRAME.asSeconds() 
        * _mMovementVector;
    
    _mSprite.move(_mMovementVector);
}

sf::Sprite Player::GetSprite() const {
    return _mSprite;
}

sf::Vector2f Player::GetPosition() const {
    return _mPosition;
}

sf::Vector2f Player::GetMovementVector() const  {
    return _mMovementVector;
}

void Player::SetMovementMap(const umap<Moving, bool>& map) {
    _movementMap = map;
}
