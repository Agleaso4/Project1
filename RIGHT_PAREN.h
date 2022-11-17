//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_RIGHT_PAREN_H
#define PROJECT_1_RIGHT_PAREN_H


#include "Automaton.h"

class RIGHT_PAREN : public Automaton
{
private:

public:
    RIGHT_PAREN() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == ')') { //RIGHT_PAREN
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};




#endif //PROJECT_1_RIGHT_PAREN_H
