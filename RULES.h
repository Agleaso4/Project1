//
// Created by Ammon on 9/16/2022.
//

#ifndef PROJECT_1_RULES_H
#define PROJECT_1_RULES_H

#include "Automaton.h"

class RULES : public Automaton
{
private:
    void S1(const std::string& input){
        if (input[index] == 'u') {
            inputRead++;
            index++;
            S2(input);
        }
        else {
            Serr();
        }
    }
    void S2(const std::string& input){
        if (input[index] == 'l') {
            inputRead++;
            index++;
            S3(input);
        }
        else {
            Serr();
        }
    }
    void S3(const std::string& input){
        if (input[index] == 'e') {
            inputRead++;
            index++;
            S4(input);
        }
        else {
            Serr();
        }
    }
    void S4(const std::string& input){
        if (input[index] == 's') {
            inputRead++;
            //Todo go into accept state
        }
        else {
            Serr();
        }
    }

public:
    RULES() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == 'R') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }

};

#endif //PROJECT_1_RULES_H
