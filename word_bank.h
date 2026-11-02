#ifndef WORD_BANK_H
#define WORD_BANK_H

#include <random>
#include <string>
#include <vector>

class WordBank {
private:
    std::vector<std::string> words_;
    std::mt19937 randomEngine_;

public:
    WordBank();

    std::string randomWord();
};

#endif
