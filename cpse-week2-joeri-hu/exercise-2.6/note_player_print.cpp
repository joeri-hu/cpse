#include <iostream>
#include "note_player_print.hpp"
  
void note_player_print::play(note const& n) {
    std::cout << "note: "
        << n.frequency << ", "
        << n.duration << '\n';
}
