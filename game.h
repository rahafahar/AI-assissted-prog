#ifndef GAME_H
#define GAME_H

#include "word_bank.h"

#include <iosfwd>

class Game {
private:
    WordBank wordBank_;
    std::istream& input_;
    std::ostream& output_;

public:
    Game();
    Game(WordBank wordBank, std::istream& input, std::ostream& output);

    void play();
};

#endif
