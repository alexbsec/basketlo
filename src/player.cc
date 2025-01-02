#include "include/player.hpp"
#include "include/utils.hpp"
#include <SFML/Graphics/Rect.hpp>

const string PLAYER_ASSET_PATH = "./assets/characters/1/D_Idle.png";

// Start position of the Idle Sprite
const int X_START = 9; //13;
const int Y_START = 3; //18;

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

Player::Player() 
    : _mMovementVector()
    , _mPosition()
    , _mSprite() 
    , _mTexture() {
    if (!_mTexture.loadFromFile(
        PLAYER_ASSET_PATH,
        sf::IntRect(X_START, Y_START, X_PIXELS, Y_PIXELS) 
    )) {
       // Handle loading error
    }
    _mSprite.setTexture(_mTexture);
    _mSprite.setPosition(100.0f, 100.0f);
    _mSprite.setScale(X_SCALE, Y_SCALE);

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
