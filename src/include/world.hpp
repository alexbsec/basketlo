#ifndef _BASKTLO_WORLD_HPP
#define _BASKTLO_WORLD_HPP

#include "player.hpp"
#include "resource_holder.hpp"
#include "scene_node.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <array>

class World : private sf::NonCopyable {
public:
  explicit World(sf::RenderWindow &window);
  void Update(sf::Time deltaTime);
  void Draw();
  void ProcessEvents();

private:
  void LoadTextures();
  void BuildScene();

  enum Layer { Background, Foreground, LayerCount };

  InputManager *_inputManager;
  sf::RenderWindow &_mWindow;
  sf::View _mWorldView;
  TextureHolder _mTextures;
  SceneNode _mSceneGraph;
  std::array<SceneNode *, LayerCount> _mSceneLayers;
  sf::FloatRect _mWorldBounds;
  sf::Vector2f _mSpawnPosition;
  Player *_mPlayer;
};

#endif
