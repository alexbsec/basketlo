#include "include/utils.hpp"

namespace utils {
void NormalizeVector2f(sf::Vector2f &vec) {
  float len = sqrt(vec.x * vec.x + vec.y * vec.y);
  if (len != 0) {
    vec.x = vec.x / len;
    vec.y = vec.y / len;
  }
}

float GetVector2fMaginitude(const sf::Vector2f &vec) {
  return sqrt(vec.x * vec.x + vec.y * vec.y);
}
} // namespace utils
