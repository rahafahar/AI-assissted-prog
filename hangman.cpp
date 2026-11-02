#include "hangman.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace {
char normalize(char letter) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(letter)));
}
}

Hangman::Hangman(std::string wordGuess)
    : Hangman(wordGuess, 6) {}

Hangman::Hangman(const std::string& wordGuess, int maxAttempts)
    : letterCount(0),
      secretWord(wordGuess),
      attemptsRemaining_(maxAttempts) {
    if (secretWord.empty()) {
        throw std::invalid_argument("The secret word cannot be empty.");
    }
    if (maxAttempts <= 0) {
        throw std::invalid_argument("The number of attempts must be positive.");
    }

    for (char& letter : secretWord) {
        const unsigned char value = static_cast<unsigned char>(letter);
        if (!std::isalpha(value)) {
            throw std::invalid_argument("The secret word must contain only letters.");
        }
        letter = normalize(letter);
    }
}

GuessResult Hangman::submitGuess(const Guess& guess) {
    if (isFinished()) {
        return GuessResult::Finished;
    }
    if (!guess.isValid()) {
        return GuessResult::Invalid;
    }

    const char letter = guess.letter();
    if (hasGuessed(letter)) {
        return GuessResult::AlreadyGuessed;
    }

    guessedLetters_ += letter;
    ++letterCount;
    if (isCorrect(letter)) {
        return GuessResult::Correct;
    }

    --attemptsRemaining_;
    return GuessResult::Incorrect;
}

bool Hangman::isCorrect(char L) {
    return static_cast<const Hangman&>(*this).isCorrect(L);
}

bool Hangman::isCorrect(char letter) const {
    return secretWord.find(normalize(letter)) != std::string::npos;
}

bool Hangman::hasGuessed(char letter) const {
    return guessedLetters_.find(normalize(letter)) != std::string::npos;
}

bool Hangman::hasWon() const {
    return std::all_of(secretWord.begin(), secretWord.end(), [this](char letter) {
        return hasGuessed(letter);
    });
}

bool Hangman::hasLost() const {
    return attemptsRemaining_ == 0;
}

bool Hangman::isFinished() const {
    return hasWon() || hasLost();
}

int Hangman::attemptsRemaining() const {
    return attemptsRemaining_;
}

const std::string& Hangman::guessedLetters() const {
    return guessedLetters_;
}

const std::string& Hangman::getSecretWord() const {
    return secretWord;
}

std::string Hangman::maskedWord() const {
    std::string result;
    for (char letter : secretWord) {
        if (!result.empty()) {
            result += ' ';
        }
        result += hasGuessed(letter) ? letter : '_';
    }
    return result;
}

int Hangman::attempts(int n) {
    return n > 0 && n <= 10 && attemptsRemaining_ > 0 ? n : 0;
}
