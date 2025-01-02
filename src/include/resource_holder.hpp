#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <cassert>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

template <typename T, typename Q> using umap = std::unordered_map<T, Q>;

using string = std::string;

namespace textures {
enum PlayerTexture { Idle1, Idle2, Idle3, Idle4 };

const std::vector<PlayerTexture> PLAYER_TEXTURES = {
    PlayerTexture::Idle1, PlayerTexture::Idle2, PlayerTexture::Idle3,
    PlayerTexture::Idle4};

} // namespace textures

template <typename Resource, typename Identifier> class ResourceHolder {
public:
  void Load(Identifier id, const std::string &filepath,
            const sf::IntRect &area = sf::IntRect()) {
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filepath, area)) {
      throw std::runtime_error("ResourceHolder::Load - Failed to load " +
                               filepath);
    }
    auto insertedPair =
        _mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(insertedPair.second);
  }

  Resource &Get(Identifier id) {
    auto found = _mResourceMap.find(id);
    assert(found != _mResourceMap.end());
    return *found->second;
  }

  const Resource &Get(Identifier id) const {
    auto found = _mResourceMap.find(id);
    assert(found != _mResourceMap.end());
    return *found->second;
  }

private:
  umap<Identifier, std::unique_ptr<Resource>> _mResourceMap;
};
