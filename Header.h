//
// Created by Ammon on 10/21/2022.
//

#ifndef PROJECT_1_HEADER_H
#define PROJECT_1_HEADER_H

#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include "Datalog.h"

using namespace std;

class Header{
public:
    explicit Header(vector<string> Attributes){
        attributes = std::move(Attributes);
    }

    vector<string> attributes;

    vector<string> projectHeader(const vector<int>& placeValue) {
        vector<string> stringOfAttributes;
        for(int i : placeValue){
            stringOfAttributes.push_back(attributes[i]);
        }
        return stringOfAttributes;
    }
};

#endif //PROJECT_1_HEADER_H
