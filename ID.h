//
// Created by Ammon on 9/16/2022.
//

#ifndef PROJECT_1_ID_H
#define PROJECT_1_ID_H

#include "Automaton.h"
#include <iostream>
class ID : public Automaton
{
private:
    void S1(const std::string& input){
        if (isalnum(input[index])) {
            inputRead++;
            index++;
            S1(input);
        }
        else if(input[index] == '\n' || input[index] == ' '){
            //inputRead++;
            index++;
        }
        else if(!isalpha(input[index])){
            //inputRead++;
            index++;
        }
        else {
            //TODO need to end ID and record and then start Lexer again at new place
            Serr();
        }
    }

public:
    ID() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (isalpha(input[index])) {
            inputRead++;
            index++;
            S1(input);
        } else if (input[index] == '\n' || input[index] == ' ' || !isalnum(input[index])) {
            index++;

        } else {
            Serr();
        }
    }
};


#endif //PROJECT_1_ID_H
