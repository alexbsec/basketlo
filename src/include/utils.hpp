#ifndef _BASKTLO_UTILS_HPP
#define _BASKTLO_UTILS_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace utils {
const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / 60.0f);
const unsigned int WINDOW_WIDTH = 1920;
const unsigned int WINDOW_HEIGHT = 1080;

void NormalizeVector2f(sf::Vector2f &vec);
float GetVector2fMaginitude(const sf::Vector2f &vec);
} // namespace utils
#endif
