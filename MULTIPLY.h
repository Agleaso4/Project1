//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_MULTIPLY_H
#define PROJECT_1_MULTIPLY_H


#include "Automaton.h"

class MULTIPLY : public Automaton
{
private:

public:
    MULTIPLY() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '*') { //MULTIPLY
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};


#endif //PROJECT_1_MULTIPLY_H
