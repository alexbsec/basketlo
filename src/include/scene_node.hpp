#ifndef _BASKTLO_SCENE_NODE_HPP
#define _BASKTLO_SCENE_NODE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <memory>
#include <vector>

template <typename T> using vector = std::vector<T>;

class SceneNode : public sf::Transformable,
                  public sf::Drawable,
                  private sf::NonCopyable {
public:
  typedef std::unique_ptr<SceneNode> Ptr;
  SceneNode();
  void AttachChild(Ptr child);
  Ptr DetachChild(const SceneNode &node);

private:
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const final;
  virtual void DrawCurrent(sf::RenderTarget &target,
                           sf::RenderStates states) const;

  vector<Ptr> _mChildren;
  SceneNode *_mParent;
};

// Usage:
// sf::RenderWindow window(...);
// SceneNode::Ptr node(...);
// window.draw(*node);

#endif
