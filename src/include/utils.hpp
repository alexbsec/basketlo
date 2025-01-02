#ifndef _BASKTLO_UTILS_HPP
#define _BASKTLO_UTILS_HPP

#include <SFML/System/Time.hpp>
#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace utils {
    const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / 60.0f);
    void NormalizeVector2f(sf::Vector2f& vec); 
}
#endif
