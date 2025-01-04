#include "include/game.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main() {
  try {
    string title = "basktlo";
    Game game(title);

    game.Run();
  } catch (std::exception& e) {
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
