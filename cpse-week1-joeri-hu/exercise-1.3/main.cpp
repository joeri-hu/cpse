#include "hwlib.hpp"

extern "C" void print_asciz(const char *s);
extern "C" void application();

extern "C" char convert_char(char letter) {
    if ((letter >= 'A' and letter <= 'Z')
        or (letter >= 'a' and letter <= 'z')
    ) {
        letter xor_eq 'a' - 'A';
    }
    return letter;
}

extern "C" void uart_put_char(char c) {
    hwlib::cout << c;
}

int main() {
    hwlib::wait_ms(1'000);
    application();
}
