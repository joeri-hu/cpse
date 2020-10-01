#ifndef _NOTE_PLAYER_CONVERT_HPP
#define _NOTE_PLAYER_CONVERT_HPP

#include "note_player.hpp"
#include <fstream>
#include <string>

class note_player_convert : public note_player {
private:
    static const std::string extension;
    std::string name;
    std::ofstream melody;

    void header();
    void footer();
public: 
    note_player_convert(
        std::string const& name
    );
    ~note_player_convert();

    void play(note const& n) override;
};

#endif
