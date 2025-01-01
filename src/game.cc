#include "include/game.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 640;
const float RADIUS = 10.0f;

Game::Game(const string& title)
    : _mWindow(sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title))
    , _mPlayer(sf::CircleShape(RADIUS)) {
    _movementMap[Moving::UP] = false;
    _movementMap[Moving::DOWN] = false;
    _movementMap[Moving::LEFT] = false;
    _movementMap[Moving::RIGHT] = false;
}

void Game::Run() {
    while (_mWindow.isOpen()) {
        ProcessEvents();
        Update();
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
