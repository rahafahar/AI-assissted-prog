#ifndef HANGMAN
#define HANGMAN
#include "guess.h"

class Hangman{

    private:
    int letterCount;
    std::string secretWord;

    public:
    Hangman(std::string wordGuess); //constructor
    bool isCorrect(char L); //checks if letter guessed is correct or not

    
};
#endif