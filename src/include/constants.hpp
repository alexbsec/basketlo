#ifndef _BASKTLO_CONSTANTS_HPP
#define _BASKTLO_CONSTANTS_HPP

#include <string>

using string = std::string;

namespace consts {
// Start position of the Idle Sprite
const int X_START = 9;
const int Y_START = 3;

// Size of the int rectangle containing the sprite
const int X_PIXELS = 13;
const int Y_PIXELS = 18;

// idle animation offset
const int X_OFFSET = 32;

// Aspect Ratio
const float ASPECT_RATIO = (float)X_PIXELS / Y_PIXELS;

/* PLAYER CONSTANTS */
/********************/

// Player Scaling
const float PLAYER_HEIGHT = 60.0f;
const float X_SCALE = (ASPECT_RATIO * PLAYER_HEIGHT) / X_PIXELS;
const float Y_SCALE = PLAYER_HEIGHT / Y_PIXELS;
const float PLAYER_SPEED = 40.0f;

// Texture assets paths
const string ARCHER_TEXTURE_PATH = "assets/characters/1/D_Idle.png";
const string WARRIOR_TEXTURE_PATH = "assets/characters/2/D_Idle.png";
const string MAGE_TEXTURE_PATH = "assets/characters/3/D_Idle.png";
} // namespace consts

#endif
