//
// Created by Ammon on 10/21/2022.
//

#ifndef PROJECT_1_TUPLE_H
#define PROJECT_1_TUPLE_H

#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include "P4Relations.h"

using namespace std;

class TupleP2{
public:
    vector<string> values;
    explicit TupleP2(vector<string> tuples){
        values = std::move(tuples);
    }
    vector<string> printTupleP2(const vector<int>& tupleIndex){
        vector<string> indexT;
        for(int i : tupleIndex){
            indexT.push_back(values[i]);
        }
        return indexT;
    }
    bool operator< (const TupleP2 &rhs) const{
        return values < rhs.values;
    }
};

#endif //PROJECT_1_TUPLE_H
