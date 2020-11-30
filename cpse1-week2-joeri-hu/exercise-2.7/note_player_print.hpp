#ifndef _NOTE_PLAYER_PRINT_HPP
#define _NOTE_PLAYER_PRINT_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player for a terminal running on a desktop
//
// ===========================================================================

class note_player_print : public note_player {
public: 
    note_player_print() = default;

    void play(note const& n) override;
};

#endif
