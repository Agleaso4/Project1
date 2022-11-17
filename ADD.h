//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_ADD_H
#define PROJECT_1_ADD_H

#include "Automaton.h"

class ADD : public Automaton
{
private:

public:
    ADD() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '+') { //ADD
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};

#endif //PROJECT_1_ADD_H
