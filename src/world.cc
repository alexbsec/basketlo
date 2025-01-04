#include "include/world.hpp"
#include "include/constants.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

World::World(sf::RenderWindow &window)
    : _inputManager(nullptr), _mWindow(window),
      _mWorldView(window.getDefaultView()),
      _mWorldBounds(0.0f, 0.0f, _mWorldView.getSize().x, 2000.0f),
      _mSpawnPosition(_mWorldView.getSize().x / 2.0f,
                      _mWorldBounds.height - _mWorldView.getSize().y),
      _mPlayer(nullptr) {

  LoadTextures();
  BuildScene();

  _mWorldView.setCenter(_mSpawnPosition);
}

void World::Update(sf::Time deltaTime) {
  ProcessEvents();
  _mSceneGraph.Update(deltaTime);
  _mPlayer->HandleMovement();
}

void World::ProcessEvents() {
  sf::Event event;

  if (_inputManager == nullptr) {
    _inputManager = new InputManager(event);
  }

  while (_mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      _mWindow.close();
    }
    _mPlayer->SetMovementMap(_inputManager->GetMovementInput());
  }
}

void World::Draw() {
  _mWindow.setView(_mWorldView);
  _mWindow.draw(_mSceneGraph);
}

void World::LoadTextures() {
  sf::IntRect spriteSpecs(consts::X_START, consts::Y_START, consts::X_PIXELS,
                          consts::Y_PIXELS);
  _mTextures.Load(textures::Archer, consts::ARCHER_TEXTURE_PATH, spriteSpecs);
  _mTextures.Load(textures::Warrior, consts::WARRIOR_TEXTURE_PATH, spriteSpecs);
  _mTextures.Load(textures::Mage, consts::MAGE_TEXTURE_PATH, spriteSpecs);
}

void World::BuildScene() {
  for (std::size_t i = 0; i < LayerCount; i++) {
    SceneNode::Ptr layer(new SceneNode());
    _mSceneLayers[i] = layer.get();
    _mSceneGraph.AttachChild(std::move(layer));
  }

  // Here we would load the map
  // sf::Texture& texture = _mTextures.Get(textures::Map)

  std::unique_ptr<Player> leader(new Player(Player::Archer, _mTextures));
  _mPlayer = leader.get();
  _mPlayer->setPosition(_mSpawnPosition);
  _mPlayer->setScale(consts::X_SCALE, consts::Y_SCALE);
  _mSceneLayers[Foreground]->AttachChild(std::move(leader));
}
