//
// Created by Ammon on 10/6/2022.
//

#ifndef PROJECT_1_P2RULES_H
#define PROJECT_1_P2RULES_H

#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <vector>
#include "Parameter.h"
#include "Predicate.h"

using namespace std;

class P2Rules {
private:
    Predicate* headPredicate;
    vector<Predicate*> rulesBody;
public:
    P2Rules() = default;
    void setHeadPredicate(Predicate* headPred){
        this->headPredicate=headPred;
    }
    void addBodyPredicate(Predicate* bodyPredicate){
        this->rulesBody.push_back(bodyPredicate);
    }
    string ruleToString(){
        stringstream ss;

        ss << headPredicate->predToString() << " :- ";
        for(unsigned int i = 0; i < rulesBody.size(); i++){
            ss << rulesBody.at(i)->predToString();
            if(i != rulesBody.size()-1){
                ss << ",";
            }
        }
        return ss.str();
    }
    vector<Predicate *> getBodyPredicate(){
        return rulesBody;
    }
    static string toString() {
        return std::string();
    }
};


#endif //PROJECT_1_P2RULES_H
