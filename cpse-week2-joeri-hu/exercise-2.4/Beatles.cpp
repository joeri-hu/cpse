#ifndef _Beatles_HPP
#define _Beatles_HPP

#include "melody.hpp"

class Beatles : public melody {
public:
    void play(note_player& player) {
        player.play({1318, 150000});
        player.play({1174, 300000});
        player.play({1046, 600000});
        player.play({1318, 150000});
        player.play({1568, 300000});
        player.play({1760, 300000});
        player.play({1568, 300000});
        player.play({1568, 150000});
        player.play({1568, 300000});
        player.play({1318, 300000});
        player.play({1174, 150000});
        player.play({1046, 300000});
        player.play({880, 150000});
        player.play({784, 300000});
        player.play({1318, 600000});
        player.play({0, 600000});
        player.play({1318, 300000});
        player.play({1318, 150000});
        player.play({1396, 300000});
        player.play({1318, 300000});
        player.play({1318, 300000});
        player.play({1174, 300000});
        player.play({0, 150000});
        player.play({1318, 150000});
        player.play({1174, 150000});
        player.play({1174, 300000});
        player.play({1046, 1200000});
    }
};

#endif
