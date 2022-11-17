//
// Created by Ammon on 9/16/2022.
//

#ifndef PROJECT_1_FACTS_H
#define PROJECT_1_FACTS_H

#include "Automaton.h"

class FACTS : public Automaton
{
private:
    void S1(const std::string& input){
        if (input[index] == 'a') {
            inputRead++;
            index++;
            S2(input);
        }
        else {
            Serr();
        }
    }
    void S2(const std::string& input){
        if (input[index] == 'c') {
            inputRead++;
            index++;
            S3(input);
        }
        else {
            Serr();
        }
    }
    void S3(const std::string& input){
        if (input[index] == 't') {
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
        }
        else {
            Serr();
        }
    }

public:
    FACTS() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == 'F') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }

};



#endif //PROJECT_1_FACTS_H
