#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <fstream>
#include <string>

class generator {
private:
    std::ofstream& output;
    std::string message;

    void header();
    void footer();
public:
    generator(std::ofstream& output);
    ~generator();

    void body(char letter);
};

#endif // GENERATOR_HPP
