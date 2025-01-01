#include <cmath>
#include <iostream>
#include "include/game.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 640;
const float RADIUS = 10.0f;
const float PLAYER_SPEED = 200.0f;
const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / 60.0f);

Game::Game(const string& title)
    : _mWindow(sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title))
    , _mPlayer(sf::CircleShape(RADIUS)) {
    _movementMap[Moving::UP] = false;
    _movementMap[Moving::DOWN] = false;
    _movementMap[Moving::LEFT] = false;
    _movementMap[Moving::RIGHT] = false;
}

void Game::Run() {
    _deltaTime = sf::Time::Zero;
    while (_mWindow.isOpen()) {
        FixedTimeUpdate();
        Render();
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (_mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed: {
                HandlePlayerInput(event.key.code, true);
                break;
            } 

            case sf::Event::KeyReleased: {
                HandlePlayerInput(event.key.code, false);
                break;
            }

            case sf::Event::Closed: {
                _mWindow.close();
                break;
            }

            default:
                break;
        }
    }
}

void Game::Update() {
    sf::Vector2f movementVector(0.0f, 0.0f);
    
    if (_movementMap[Moving::UP]) {
        movementVector.y -= 1.0f;
    }

    if (_movementMap[Moving::DOWN]) {
        movementVector.y += 1.0f;
    }

    if (_movementMap[Moving::LEFT]) {
        movementVector.x -= 1.0f;
    }

    if (_movementMap[Moving::RIGHT]) {
        movementVector.x += 1.0f;
    }

    NormalizeMovement(movementVector);
    movementVector = PLAYER_SPEED * TIME_PER_FRAME.asSeconds() * movementVector;

    std::cout << "[" << movementVector.x << ", " << movementVector.y << "]"
        << std::endl;

    _mPlayer.move(movementVector);
}

void Game::Render() {
    _mWindow.clear();
    _mWindow.draw(_mPlayer);
    _mWindow.display();
}

void Game::HandlePlayerInput(sf::Keyboard::Key keyCode, bool isPressed) {
    if (keyCode == sf::Keyboard::Key::W) {
        _movementMap[Moving::UP] = isPressed; 
    }

    if (keyCode == sf::Keyboard::Key::S) {
        _movementMap[Moving::DOWN] = isPressed;
    }

    if (keyCode == sf::Keyboard::Key::A) {
        _movementMap[Moving::LEFT] = isPressed;
    }

    if (keyCode == sf::Keyboard::Key::D) {
        _movementMap[Moving::RIGHT] = isPressed;
    }
}

void Game::FixedTimeUpdate() {
    ProcessEvents();
    _deltaTime += _mClock.restart();
    while (_deltaTime > TIME_PER_FRAME) {
        _deltaTime -= TIME_PER_FRAME;
        ProcessEvents();
        Update();
    }
}

void Game::NormalizeMovement(sf::Vector2f& movVec) {
    float len = sqrt(movVec.x * movVec.x + movVec.y * movVec.y);
    if (len != 0) {
        movVec.x = movVec.x / len;
        movVec.y = movVec.y / len;
    }
}
