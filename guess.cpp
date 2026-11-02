#include "guess.h"

#include <cctype>

Guess::Guess(char userGuess) : letter_(static_cast<char>(
                                   std::tolower(static_cast<unsigned char>(userGuess)))) {}

char Guess::letter() const {
    return letter_;
}

bool Guess::isValid() const {
    return std::isalpha(static_cast<unsigned char>(letter_)) != 0;
}
