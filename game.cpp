#include "game.h"

#include "guess.h"
#include "hangman.h"

#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

namespace {
constexpr int kMaxAttempts = 6;

void displayRound(std::ostream& output, const Hangman& round) {
    const int incorrectGuesses = kMaxAttempts - round.attemptsRemaining();
    output << "\nWord: " << round.maskedWord()
           << "\nIncorrect guesses: " << incorrectGuesses << '/' << kMaxAttempts
           << "\nAttempts remaining: " << round.attemptsRemaining()
           << "\nGuessed letters: ";

    if (round.guessedLetters().empty()) {
        output << "(none)";
    } else {
        for (std::size_t index = 0; index < round.guessedLetters().size(); ++index) {
            if (index > 0) {
                output << ", ";
            }
            output << round.guessedLetters()[index];
        }
    }
    output << "\n";
}
}

Game::Game() : Game(WordBank(), std::cin, std::cout) {}

Game::Game(WordBank wordBank, std::istream& input, std::ostream& output)
    : wordBank_(std::move(wordBank)), input_(input), output_(output) {}

void Game::play() {
    Hangman round(wordBank_.randomWord(), kMaxAttempts);
    output_ << "Welcome to Hangman! Guess one letter at a time.\n";

    while (!round.isFinished()) {
        displayRound(output_, round);
        output_ << "Your guess: " << std::flush;

        std::string inputLine;
        if (!std::getline(input_, inputLine)) {
            output_ << "\nInput ended; the game was stopped.\n";
            return;
        }
        if (inputLine.size() != 1) {
            output_ << "Please enter exactly one letter.\n";
            continue;
        }

        const Guess guess(inputLine.front());
        switch (round.submitGuess(guess)) {
        case GuessResult::Correct:
            output_ << "Correct!\n";
            break;
        case GuessResult::Incorrect:
            output_ << "Sorry, that letter is not in the word.\n";
            break;
        case GuessResult::AlreadyGuessed:
            output_ << "You already guessed that letter.\n";
            break;
        case GuessResult::Invalid:
            output_ << "Please enter a letter from A to Z.\n";
            break;
        case GuessResult::Finished:
            break;
        }
    }

    displayRound(output_, round);
    if (round.hasWon()) {
        output_ << "You win! The word was " << round.getSecretWord() << ".\n";
    } else {
        output_ << "You lose. The word was " << round.getSecretWord() << ".\n";
    }
}
