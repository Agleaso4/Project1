//
// Created by Ammon on 9/16/2022.
//

#ifndef PROJECT_1_STRING_H
#define PROJECT_1_STRING_H


#include "Automaton.h"

class STRING : public Automaton
{
private:
    void S1(const std::string& input){
        if (index >= input.size()){
            type = TokenType::UNDEFINED;
            return;
        }
        else if (input[index] != '\'') {
            if (input[index] == '\n')
                newLines++;
            inputRead++;
            index++;
            S1(input);
        }
        else if(input[index] == '\''){
            inputRead++;
            index++;
            if(input[index] == '\''){
                index++;
                inputRead++;
                S1(input);
            }
        } else {
            Serr();
        }
    }

public:
    STRING() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input){
        if(input[index] == '\''){
            inputRead++;
            index++;
            S1(input);
        }
        else{
            Serr();
        }
    }
};


#endif //PROJECT_1_STRING_H
