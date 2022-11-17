//
// Created by Ammon on 11/16/2022.
//

#ifndef PROJECT_1_P4RELATIONS_H
#define PROJECT_1_P4RELATIONS_H
//
// Created by Ammon on 11/14/2022.
//

#include "Header.h"
#include "Tuple.h"
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstring>

using namespace std;

class P4Relations {
private:
    string name;
    Header* header;
public:
    set<TupleP2> tuplesRelation;

    string getName() {
        return name;
    }
    Header setHeader(Header header1){
        return header1;
    }

    Header* getHeader(){
        return header;
    }

    P4Relations(string tupleName, Header* head) {
        name = std::move(tupleName);
        header = head;
    }

//    select: parameters are index and value (relation column and value to select)
    P4Relations *SelectValue(int column, const string& value) {
        set<TupleP2> tupls;
        for (TupleP2 tupleP2: tuplesRelation) {
            if (tupleP2.values[column] == value) {
                tupls.insert(tupleP2);
            }
        }
        auto *relationObj = new P4Relations(this->name, this->header);
        relationObj->tuplesRelation = tupls;
        return relationObj;
    }

//    select: parameters are index and index (relation columns to select on same values)
    P4Relations *SelectIndex(int column, int row) {
        set<TupleP2> tupls;
        for (TupleP2 tupleP2: tuplesRelation) {
            if (tupleP2.values[column] == tupleP2.values[row]) {
                tupls.insert(tupleP2);
            }
        }
        auto* relation = new P4Relations(this->name, this->header);
        relation->tuplesRelation = tupls;
        return relation;
    }

//    project: parameter is a vector of integers which will be the columns
    P4Relations *project(const vector<int>& columns) {
        vector<string> h = header->projectHeader(columns);
        auto *head = new Header(h);
        auto *relation = new P4Relations(this->name, head);
        set<TupleP2> tupls;
        for (TupleP2 t: tuplesRelation) {
            vector<string> s = t.printTupleP2(columns);
            TupleP2 tupl(s);
            tupls.insert(tupl);
        }
        relation->tuplesRelation = tupls;
        return relation;
    }

//    rename: parameter is a vector of strings which are the column headers
    P4Relations *rename(vector<string> colHeaders) {
        auto* head = new Header(std::move(colHeaders));
        auto* relation1 = new P4Relations(this->name, head);
        relation1->tuplesRelation = this->tuplesRelation;
        return relation1;
    }

    Header combineHeaders(P4Relations combine){

    }

    TupleP2 combineTuples(){
        auto combinedTupls = new 
        //if tuples match return true
        //else return false
        return combinedTupls;
    }

    P4Relations naturalJoin(P4Relations anotherRel){
        auto joinedRelation = new P4Relations(this->name, header);
        joinedRelation->setHeader(combineHeaders(anotherRel));
        //if(true){
        //for each tuple{
        //combineTuples
        //if(true){
        //add tuple to table/vec}
        //else{
        //do nothing}
        //add to database}
        //else{do nothing}
        //}
        return *joinedRelation;
    }

};
#endif //PROJECT_1_P4RELATIONS_H
