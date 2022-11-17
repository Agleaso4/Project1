#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "SCHEMES.h"
#include "FACTS.h"
#include "RULES.h"
#include "QUERIES.h"
#include "ID.h"
#include "STRING.h"
#include "COMMENT.h"
#include <string>
#include "Automaton.h"
#include "Token.h"
#include "COMMAS.h"
#include "PERIOD.h"
#include "RIGHT_PAREN.h"
#include "LEFT_PAREN.h"
#include "Q_MARK.h"
#include "MULTIPLY.h"
#include "ADD.h"
#include <iostream>

using namespace std;
Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    automata.clear();
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new COMMAS);
    automata.push_back(new PERIOD);
    automata.push_back(new RIGHT_PAREN);
    automata.push_back(new LEFT_PAREN);
    automata.push_back(new Q_MARK);
    automata.push_back(new MULTIPLY);
    automata.push_back(new ADD);
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new SCHEMES());
    automata.push_back(new FACTS());
    automata.push_back(new RULES());
    automata.push_back(new QUERIES());
    automata.push_back(new ID());
    automata.push_back(new STRING());
    automata.push_back(new COMMENT());
}

vector<Token *> Lexer::Run() {
    int lineNumber = 1;
    while(input.size() > 0){
        int maxRead = 0;
        Automaton *maxAutomaton;
        while(isspace(input[0])){
            if(input[0] == '\n'){
                lineNumber++;
            }
            else if(isspace(input.size()==0)){
                break;
            }
            input.erase(0,1);
        }


    //TODO find a way to get rid of the white spaces
        for(Automaton* automatonPresent : automata){
            int startRead = automatonPresent->Start(input);
            if(startRead > maxRead){
                maxRead = startRead;
                maxAutomaton = automatonPresent;
            }
        }
        if(maxRead == 0 && !input.empty()){
            maxRead = 1;
            tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0,1), lineNumber));//creating the undefined token
        }
        else if(maxRead > 0){
            Token* AB = maxAutomaton->CreateToken(input.substr(0,maxRead), lineNumber);
            if(AB->getType()!= TokenType::COMMENT) {
                tokens.push_back(AB);
            }
            lineNumber += maxAutomaton->NewLinesRead();
            //lineNumber++;
        }
        input.erase(0,maxRead);
    }
    tokens.push_back(new Token(TokenType::FSA_EOF, "", lineNumber));//creating the EOF token
    //getTokens();
    //print(tokens);
    return tokens;
}


void Lexer::print(const std::vector<Token*> &tokens)
{
    for (Token* token: tokens) {
        std::cout << token->toString() << '\n';
    }
    int count = tokens.size();
    cout << "Total Tokens = " << count;
}

const vector<Token *> &Lexer::getTokens() const {
    return tokens;
}