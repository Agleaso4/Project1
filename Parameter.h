//
// Created by Ammon on 10/5/2022.
//

#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H
#include <string>

using namespace std;

class Parameter {
private:

public:
    string parameterVal;
    Parameter() = default;
    Parameter(string tempPar){
        parameterVal = tempPar;
    }
    string parToString(){
        return parameterVal;
    }
    void stringParAdd(string addToPar){
        parameterVal = addToPar;
    }
};


#endif //PROJECT_1_PARAMETER_H
