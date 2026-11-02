#ifndef HANGMAN
#define HANGMAN

#include "guess.h"
#include <string>

enum class GuessResult {
    Correct,
    Incorrect,
    AlreadyGuessed,
    Invalid,
    Finished
};

class Hangman {
private:
    int letterCount;
    std::string secretWord;
    std::string guessedLetters_;
    int attemptsRemaining_;

public:
    Hangman(std::string wordGuess); // constructor
    Hangman(const std::string& wordGuess, int maxAttempts);

    GuessResult submitGuess(const Guess& guess);
    bool isCorrect(char L); // checks if letter guessed is correct or not
    bool isCorrect(char letter) const;
    bool hasGuessed(char letter) const;
    bool hasWon() const;
    bool hasLost() const;
    bool isFinished() const;
    int attemptsRemaining() const;
    const std::string& guessedLetters() const;
    const std::string& getSecretWord() const;
    std::string maskedWord() const;
    int attempts(int n); // checks whether the attempt count is valid and attempts remain
};

#endif
