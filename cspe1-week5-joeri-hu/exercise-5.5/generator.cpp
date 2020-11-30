#include "generator.hpp"

generator::generator(std::ofstream& output):
    output{output}
{
    header();
}

generator::~generator() {
    footer();
}

void generator::header() {
    output <<
        ".global message\n"
        "\n"
        "message:\n";
}

void generator::body(char letter) {
    if (letter == '\n') {
        output << "    .ascii \"" << message << "\\n\"\n";
        message.clear();
    } else {
        message += letter;
    }
}

void generator::footer() {
    output << "    .asciz\n";
}
