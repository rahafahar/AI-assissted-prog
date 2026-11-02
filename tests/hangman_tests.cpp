#include "guess.h"
#include "hangman.h"

#include <cassert>
#include <stdexcept>

int main() {
    Hangman round("Cat", 2);
    assert(round.maskedWord() == "_ _ _");
    assert(round.attempts(6) == 6);
    assert(round.attempts(11) == 0);
    assert(round.submitGuess(Guess('C')) == GuessResult::Correct);
    assert(round.maskedWord() == "c _ _");
    assert(round.submitGuess(Guess('c')) == GuessResult::AlreadyGuessed);
    assert(round.attemptsRemaining() == 2);
    assert(round.submitGuess(Guess('!')) == GuessResult::Invalid);
    assert(round.attemptsRemaining() == 2);
    assert(round.submitGuess(Guess('x')) == GuessResult::Incorrect);
    assert(round.attemptsRemaining() == 1);
    assert(round.submitGuess(Guess('a')) == GuessResult::Correct);
    assert(round.submitGuess(Guess('t')) == GuessResult::Correct);
    assert(round.hasWon());
    assert(round.submitGuess(Guess('z')) == GuessResult::Finished);

    Hangman lostRound("dog", 1);
    assert(lostRound.submitGuess(Guess('x')) == GuessResult::Incorrect);
    assert(lostRound.hasLost());
    assert(lostRound.attempts(5) == 0);

    bool rejectedEmptyWord = false;
    try {
        Hangman invalidRound("", 6);
    } catch (const std::invalid_argument&) {
        rejectedEmptyWord = true;
    }
    assert(rejectedEmptyWord);
}
