//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_LEFT_PAREN_H
#define PROJECT_1_LEFT_PAREN_H


#include "Automaton.h"

class LEFT_PAREN : public Automaton
{
private:


public:
    LEFT_PAREN() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '(') { //LEFT_PAREN
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};


#endif //PROJECT_1_LEFT_PAREN_H
