#include "include/utils.hpp"
#include <SFML/System/Time.hpp>

namespace utils {
    void NormalizeVector2f(sf::Vector2f& vec) {
        float len = sqrt(vec.x * vec.x + vec.y * vec.y);
        if (len != 0) {
            vec.x = vec.x / len;
            vec.y = vec.y / len;
        }
    }
}
