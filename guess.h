#ifndef GUESS
#define GUESS

class Guess {
private:
    char letter_;

public:
    Guess(char userGuess); // takes user guess

    char letter() const;
    bool isValid() const;
};

#endif
