# Terminal Hangman

A simple single-player Hangman game written in C++17.

## Build and run

From the project directory, compile the game:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp game.cpp hangman.cpp guess.cpp word_bank.cpp -o hangman
```

Then start it:

```sh
./hangman
```

Enter one letter per turn. The game shows incorrect guesses as a tally out of six
and displays the attempts remaining. Invalid and repeated guesses do not cost an
attempt. No drawing is displayed.

## Classes

- `Guess` stores and validates one letter.
- `Hangman` tracks the secret word, guesses, and remaining attempts.
- `WordBank` chooses a word from a small built-in list.
- `Game` runs the terminal prompts and displays the round.

## Run the Hangman tests

```sh
g++ -std=c++17 -Wall -Wextra -pedantic -I. tests/hangman_tests.cpp hangman.cpp guess.cpp -o hangman_tests
./hangman_tests
```