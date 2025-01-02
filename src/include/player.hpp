#ifndef _BASKTLO_PLAYER_HPP
#define _BASKTLO_PLAYER_HPP

#include "input.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using string = std::string;

class Player {
    public:
        Player();
        void Update();    

        sf::Sprite GetSprite() const;
        sf::Vector2f GetPosition() const;
        sf::Vector2f GetMovementVector() const;
        
        void SetMovementMap(const umap<Moving, bool>& map);
        

    private:
        sf::Vector2f _mMovementVector;
        sf::Vector2f _mPosition;
        sf::Sprite _mSprite;
        sf::Texture _mTexture;
        
        const float PLAYER_SPEED = 200.0f;

        umap<Moving, bool> _movementMap;
};

#endif
