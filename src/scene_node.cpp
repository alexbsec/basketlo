#include "include/scene_node.hpp"
#include <algorithm>
#include <cassert>

void SceneNode::AttachChild(Ptr child) {
  // Sets its parent to the current node
  child->_mParent = this;
  _mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode &node) {
  auto found = std::find_if(_mChildren.begin(), _mChildren.end(),
                            [&](Ptr &p) -> bool { return p.get() == &node; });

  assert(found != _mChildren.end());
  Ptr result = std::move(*found);
  result->_mParent = nullptr;
  _mChildren.erase(found);
  return result;
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  // states.transform contains the absolut world transform 
  states.transform *= getTransform();

  // We now draw every child node
  DrawCurrent(target, states);

  // Iterate through _mChildren container of smart pointers
  // and recursively invoke draw() on each element
  for (const Ptr& child : _mChildren) {
    child->draw(target, states);
  }
}
