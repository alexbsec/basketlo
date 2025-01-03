#ifndef _BASKTLO_ENTITY_HPP
#define _BASKTLO_ENTITY_HPP

#include "scene_node.hpp"
#include <SFML/Graphics/Sprite.hpp>

class SpriteNode : public SceneNode {
public:
  explicit SpriteNode(const sf::Texture &texture);
  SpriteNode(const sf::Texture &texture, const sf::IntRect &rect);

private:
  virtual void DrawCurrent(sf::RenderTarget &target,
                           const sf::RenderStates states) const;
  
  sf::Sprite _mSprite;
};

#endif
