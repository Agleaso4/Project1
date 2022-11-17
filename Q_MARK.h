//
// Created by Ammon on 9/20/2022.
//

#ifndef PROJECT_1_Q_MARK_H
#define PROJECT_1_Q_MARK_H


#include "Automaton.h"

class Q_MARK : public Automaton
{
private:

public:
    Q_MARK() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input){
        if (input[index] == '?') { //Q_MARK
            index++;
            inputRead = 1;
        }
        else {
            Serr();
        }
    }

};




#endif //PROJECT_1_Q_MARK_H
