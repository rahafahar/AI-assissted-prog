#ifndef GUESS
#define GUESS

class Guess{

    private:
    std::string secretWord;
   // char L;
    
    public:
    Guess(char userGuess); //takes user guess
    attemps(int n); // counts if number of attempts <= 10 and if there are any attempts left
    
};
#endif