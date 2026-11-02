#include "word_bank.h"

#include <stdexcept>

WordBank::WordBank()
    : words_{"hangman", "terminal", "keyboard", "compiler", "program"},
      randomEngine_(std::random_device{}()) {}

std::string WordBank::randomWord() {
    if (words_.empty()) {
        throw std::logic_error("The word bank is empty.");
    }

    std::uniform_int_distribution<std::size_t> chooseWord(0, words_.size() - 1);
    return words_[chooseWord(randomEngine_)];
}
