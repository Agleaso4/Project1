//
// Created by Ammon on 10/5/2022.
//

#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H
#include <string>
#include <sstream>
#include <ostream>
#include <utility>
#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate {
private:
    string ID;
public:

    vector<Parameter*> parameter;
    Predicate() = default;
    Predicate(string id, vector<Parameter*> paramVec){
        ID = std::move(id);
        parameter = std::move(paramVec);
    }
    void stringPredAdd(Parameter* parameter1){
        parameter.push_back(parameter1);
    }
    void IDAdd(string id){
        ID = std::move(id);
    }
    string getPredID(){
        return ID;
    }
    string predToString(){
        stringstream ss;

        ss << ID << "(";

        for(unsigned int i = 0; i < parameter.size(); i++){
            ss << parameter.at(i)->parToString();
            if(i != parameter.size()-1){
                ss << ",";
            }
        }
        ss << ")";
        return ss.str();
    }
};


#endif //PROJECT_1_PREDICATE_H
