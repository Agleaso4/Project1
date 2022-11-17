//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_PERIOD_H
#define PROJECT_1_PERIOD_H

#include "Automaton.h"

class PERIOD : public Automaton
{
private:

public:
    PERIOD() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '.') { //PERIOD
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};

#endif //PROJECT_1_PERIOD_H
