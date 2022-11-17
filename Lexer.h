#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;

    string input;
    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer(const string& input) {
        this->input = input;
        CreateAutomata();
        Run();
    }
    ~Lexer();

    vector<Token *> Run();

    // TODO: add other public methods here

    void print(std::vector<Token*> const &input);

    const vector<Token *> &getTokens() const;
};

#endif // LEXER_H

