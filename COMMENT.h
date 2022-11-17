//
// Created by Ammon on 9/16/2022.
//

#ifndef PROJECT_1_COMMENT_H
#define PROJECT_1_COMMENT_H

#include "Automaton.h"

class COMMENT : public Automaton
{
private:
    void S1(const std::string& input){
        if (input[index] == '|') {
            inputRead++;
            index++;
            S3(input);
        }
        else if(input[index] != '|' && input[index] != '\n'){
            inputRead++;
            index++;
            S2(input);
        }
        else if (input[index] == '\n'){
            //inputRead;
            index++;
            //newLines++;
            //NewLinesRead();
            //Todo make this record in vector and delete due to accept state
        }
        else {
            Serr();
        }
    }
    void S2(const std::string& input){
        if (input[index] == '\n') {
            //inputRead++;
            index++;
            //newLines++;
            //NewLinesRead();
            //TODO this ends the comment so I need to find out how to go into an accept state and erase what we had from the string
        }
        else if (input[index] != '\n'){
            inputRead++;
            index++;
            S2(input);
        }
        else {
            Serr();
        }
    }
    void S3(const std::string& input){
        if (index >= input.size()){
            type = TokenType::UNDEFINED;
            return;
        }
        else if (input[index] == '|') {
            inputRead++;
            index++;
            S4(input);
        }
        else if (input[index] != '|'){
            if(input[index] == '\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else {
            Serr();
        }
    }
    void S4(const std::string& input){
        if (index >= input.size()){
            type = TokenType::UNDEFINED;
            return;
        }
        else if (input[index] == '#') {
            inputRead++;
            index++;
            //TODO this ends the block comment so I need to find out how to go into an accept state and erase what we had from the string
        }

        else if (input[index] != '#' && input[index] != '\0'){
            if(input[index] == '\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else {
            Serr();
        }
    }
public:
    COMMENT() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '#') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }
};


#endif //PROJECT_1_COMMENT_H
