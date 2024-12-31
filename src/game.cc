#include "include/game.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 640;
const float RADIUS = 10.0f;

Game::Game(const string& title)
    : _mWindow(sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title))
    , _mPlayer(sf::CircleShape(RADIUS)) {}
    
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
        if (event.type == sf::Event::Closed) {
            _mWindow.close();
        }
    }
}

void Game::Update() {}

void Game::Render() {
    _mWindow.clear();
    _mWindow.draw(_mPlayer);
    _mWindow.display();
}


