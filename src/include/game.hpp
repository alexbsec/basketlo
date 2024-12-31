#ifndef _BASKTLO_GAME_HPP
#define _BASKTLO_GAME_HPP

#include <SFML/Graphics.hpp>
#include <string>

using string = std::string;

class Game {
    public:
        Game(const string& title);
        void Run();

    private:
        void ProcessEvents();
        void Update();
        void Render();

        sf::RenderWindow _mWindow;
        sf::CircleShape _mPlayer;
};

#endif
