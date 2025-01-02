#include "include/game.hpp"
#include <cstdlib>

int main() {
  string title = "basktlo";
  Game game(title);

  game.Run();

  return EXIT_SUCCESS;
}
