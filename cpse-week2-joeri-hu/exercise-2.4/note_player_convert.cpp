#include "note_player_convert.hpp"
#include <fstream>

const std::string note_player_convert::extension{".cpp"};

note_player_convert::note_player_convert(
    std::string const& name
):
    name{name},
    melody{name + extension}
{
    header();
}

note_player_convert::~note_player_convert() {
    footer();
}

void note_player_convert::header() {
    melody <<
        "#ifndef _" << name << "_HPP\n"
        "#define _" << name << "_HPP\n"
        "\n"
        "#include \"melody.hpp\"\n"
        "\n"
        "class " << name << " : public melody {\n"
        "public:\n"
        "    void play(note_player& player) {\n";
}

void note_player_convert::footer() {
    melody <<
        "    }\n"
        "};\n"
        "\n"
        "#endif\n";
}

void note_player_convert::play(note const& n) {
    melody << "        player.play({"
        << n.frequency << ", " << n.duration
        << "});\n";
}
