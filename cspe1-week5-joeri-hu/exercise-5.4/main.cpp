#include "hwlib.hpp"

extern "C" void decoder();
extern "C" char read_asm();

extern "C" char read() {
    return read_asm();
}

extern "C" void write(char c) {
    hwlib::cout << c;
}

int main() {
    hwlib::wait_ms(1'000);
    decoder();
    return 0;
}
