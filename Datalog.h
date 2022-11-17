//
// Created by Ammon on 9/29/2022.
//

#ifndef PROJECT_1_DATALOG_H
#define PROJECT_1_DATALOG_H
#include <vector>
#include "Automaton.h"
#include "Lexer.h"
#include "Parameter.h"
#include "Predicate.h"
#include "RULES.h"
#include "P2Rules.h"
#include <set>

class Datalog {
protected:
    unsigned int index = 0;
public:
    Datalog(){};
    void parser(vector<Token*>);
    vector<Parameter*> currentParameters;
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<P2Rules*> rules;
    vector<Predicate*> queries;
    set<string> domain;
    string currentPredicate;
    ~Datalog();

    vector<Predicate *> GetSchemes() const;
    vector<Predicate *> GetFacts() const;
//    vector<Predicate *> GetQueries();
    vector<P2Rules *> GetRules() const;
    void predicate(Predicate* predPtr);

private:
    vector<Token*> inputTokens;
    void print();
    void match(TokenType toMatch);
    void scheme();
    void schemeList();
    void fact();
    void factList();
    void rule();
    void ruleList();
    void query();
    void queryList();
    void stringList(Predicate* predPtr);
    void idList(Predicate* predPtr);
    void headPredicate(Predicate* predPtr);

    void predicateList(P2Rules* rules1);
    void parameter(Predicate* predPtr);
    void parameterList(Predicate* predPtr);
    TokenType peek();


};


#endif //PROJECT_1_DATALOG_H
