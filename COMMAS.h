//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_COMMAS_H
#define PROJECT_1_COMMAS_H


#include "Automaton.h"

class COMMAS : public Automaton
{
private:

public:
    COMMAS() : Automaton(TokenType::COMMAS) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ',') { //COMMA
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};




#endif //PROJECT_1_COMMAS_H
