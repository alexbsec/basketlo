#ifndef _BASKTLO_GAME_HPP
#define _BASKTLO_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <unordered_map>

template <typename T, typename Q>
using umap = std::unordered_map<T, Q>;

enum class Moving {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

using string = std::string;

class Game {
    public:
        Game(const string& title);
        void Run();

    private:
        void ProcessEvents();
        void Update();
        void Render();
        void HandlePlayerInput(sf::Keyboard::Key keyCode, bool isPressed);

        sf::RenderWindow _mWindow;
        sf::CircleShape _mPlayer;
        bool _mIsMovingUp;
        bool _mIsMovingDown;
        bool _mIsMovingLeft;
        bool _mIsMovingRight;
};

#endif
