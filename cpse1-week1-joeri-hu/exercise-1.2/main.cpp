#include "hwlib.hpp"

extern "C" void uart_put_char(char c);
extern "C" void print_asciz(const char *s);
extern "C" void application();

void uart_put_char(char c) {
    hwlib::cout << c;
}

int main() {
    hwlib::wait_ms(1'000);
    application();
}
