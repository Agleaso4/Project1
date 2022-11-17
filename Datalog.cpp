//
// Created by Ammon on 9/29/2022.
//
#include "Token.h"
#include "Datalog.h"
#include "Parameter.h"
#include "Predicate.h"
#include "P2Rules.h"
#include <utility>
#include <vector>
#include <iostream>

Datalog::~Datalog() {
    inputTokens.clear();
}
void Datalog::parser(vector<Token*> input){
    inputTokens = std::move(input);
    try{
        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        scheme();
        schemeList();
        match(TokenType::FACTS);
        match(TokenType::COLON);
        factList();
        match(TokenType::RULES);
        match(TokenType::COLON);
        ruleList();
        match(TokenType::QUERIES);
        match(TokenType::COLON);
        query();
        queryList();
        match(TokenType::FSA_EOF);
        //cout << "Success!\n";
        //print();
        //Todo print function that prints all of the data structures
    }
    catch (Token* error){
        cout << "Failure!\n";
        cout << inputTokens[index]->toString();
    }
};
void Datalog::print()
{
    //schemes****************************************************
    int countScheme = schemes.size();
    cout << "Schemes(" << countScheme << "):\n";
    for (Predicate* schemes1: schemes) {
        cout << "  " << schemes1->predToString() << '\n';
    }

    //facts****************************************************
    int countFact = facts.size();
    cout << "Facts(" << countFact << "):\n";
    for (Predicate* facts1: facts) {
        cout << "  " << facts1->predToString() << '.'<< '\n';
    }
    //rules****************************************************
    int countRule = rules.size();
    cout << "Rules(" << countRule << "):\n";
    for (P2Rules* rules1: rules) {
        cout << rules1->ruleToString() << '.' << '\n';
    }
    //queries****************************************************
    int countQueries = queries.size();
    cout << "Queries(" << countQueries << "):\n";
    for (Predicate* queries1: queries) {
        cout << "  " << queries1->predToString() << "?" << '\n';
    }
    //domain****************************************************
    int countDomain = domain.size();
    cout << "Domain(" << countDomain << "):\n";
    //Todo for each Predicate in the facts, Take all the parameters in the predicate and push them onto the set
    for (const string& domain1: domain) {
        cout << "  " << domain1 <<'\n';
    }

}

void Datalog::match(TokenType toMatch) {
    if(toMatch == inputTokens[index]->getType()){
        //cout << "in match\n";
        //cout << "\t" << inputTokens[index]->toString() << endl;
        index++;
    }
    else{
        throw inputTokens[index];
    }
}

void Datalog::scheme(){
    //cout << "\t\tIn scheme \n";
    match(TokenType::ID);
    auto* newPred = new Predicate;
    newPred->IDAdd(inputTokens[index-1]->getDescription());
    match(TokenType::LEFT_PAREN);

    if(peek()==TokenType::ID){
        auto* parameter1 = new Parameter(inputTokens[index]->getDescription());

        newPred->stringPredAdd(parameter1);
    }

//    Parameter* newParam = new Parameter;
//    newParam->;//make new parameter add in predicate
    match(TokenType::ID);
    idList(newPred);
    match(TokenType::RIGHT_PAREN);
    schemes.push_back(newPred);
}

void Datalog::schemeList(){
    //cout << "\t\tIn schemeList \n";
    if(peek()==TokenType:: FACTS){
        return;
    }
    else{
        scheme();
        schemeList();
    }
}
void Datalog::fact(){
    //cout << "\t\tIn fact \n";
    match(TokenType::ID);
    auto* newPred = new Predicate;
    newPred->IDAdd(inputTokens[index-1]->getDescription());
    match(TokenType::LEFT_PAREN);
    if(peek()==TokenType::STRING){
        auto* parameter1 = new Parameter(inputTokens[index]->getDescription());
        domain.insert(parameter1->parToString());
        newPred->stringPredAdd(parameter1);
    }
    match(TokenType::STRING);

    stringList(newPred);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
    facts.push_back(newPred);
}
void Datalog::factList(){
    //cout << "\t\tIn factList \n";
    if(peek()==TokenType:: RULES){
        return;
    }
    else{
        fact();
        factList();
    }

}
void Datalog::rule(){
    //cout << "\t\tIn rule \n";
    auto* rules1 = new P2Rules();
    auto* newHeadPred = new Predicate;
    headPredicate(newHeadPred);
    rules1->setHeadPredicate(newHeadPred);


    match(TokenType::COLON_DASH);
    auto* bodyPred = new Predicate;
    predicate(bodyPred);//calling the parsing
    rules1->addBodyPredicate(bodyPred);

    predicateList(rules1);

    match(TokenType::PERIOD);
    rules.push_back(rules1);
}
void Datalog::ruleList(){
//    cout << "\t\tIn ruleList \n";
    if(peek()==TokenType:: QUERIES){
        return;
    }
    else{
        rule();
        ruleList();
    }
    
}
void Datalog::stringList(Predicate* predPtr) {
    //cout << "\t\tIn stringList \n";
    if(peek()==TokenType:: RIGHT_PAREN){
        return;
    }
    else{
        match(TokenType::COMMAS);
        if(peek()==TokenType::STRING){
            auto* p = new Parameter(inputTokens[index]->getDescription());
            domain.insert(p->parToString());
            predPtr->stringPredAdd(p);
//            Parameter* parameter1 = new Parameter(inputTokens[index]->toString());
//            currentParameters.push_back(parameter1);
        }
        match(TokenType::STRING);
        stringList(predPtr);
    }
}
void Datalog::query() {
    //cout << "\t\tIn query \n";
    auto* newPred = new Predicate;
    if(peek()==TokenType::ID){

    }
    predicate(newPred);

    match(TokenType::Q_MARK);

    queries.push_back(newPred);
}
void Datalog::queryList(){
    //cout << "\t\tIn queryList \n";
    if(peek()==TokenType:: FSA_EOF){
        return;
    }
    else{
        query();
        queryList();
    }
}
void Datalog::idList(Predicate* predPtr){
    //cout << "\t\tin idList\n";
    if(peek()==TokenType::RIGHT_PAREN){
        return;
    }
    else{
        match(TokenType::COMMAS);
        if(peek()==TokenType::ID){
            auto* p = new Parameter(inputTokens[index]->getDescription());
            predPtr->stringPredAdd(p);
        }
        match(TokenType::ID);
        //cout << "break point\n";
        idList(predPtr);
    }
}
void Datalog::headPredicate(Predicate* predPtr) {
    //cout << "\t\tIn headPredicate \n";
    if(peek()==TokenType::ID){
        predPtr->IDAdd(inputTokens[index]->getDescription());
    }
    match(TokenType::ID);

    match(TokenType::LEFT_PAREN);
    if(peek()==TokenType::ID){
        auto* p = new Parameter(inputTokens[index]->getDescription());
        predPtr->stringPredAdd(p);
    }
    match(TokenType::ID);
    idList(predPtr);
    match(TokenType::RIGHT_PAREN);
}
void Datalog::predicate(Predicate* predPtr) {
    //cout << "\t\tIn Predicate \n";
    if(peek()==TokenType::ID){
        predPtr->IDAdd(inputTokens[index]->getDescription());
    }
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);

    parameter(predPtr);
    parameterList(predPtr);

    match(TokenType::RIGHT_PAREN);
}
void Datalog::predicateList(P2Rules* rules1) {
    if(peek()==TokenType::PERIOD){
        return;
    }
    else{
        //Predicate* newPred = new Predicate;
        //newPred->IDAdd(inputTokens[index-1]->getDescription());
        match(TokenType::COMMAS);
        auto* predAdd = new Predicate();
        predicate(predAdd);
        rules1->addBodyPredicate(predAdd);
        predicateList(rules1);

    }
}
void Datalog::parameter(Predicate* predPtr) {
    //cout << "\t\tIn parameter \n";
    if(inputTokens[index]->getType()==TokenType::ID){
        if(peek()==TokenType::ID){
            auto* p = new Parameter(inputTokens[index]->getDescription());
            predPtr->stringPredAdd(p);
        }
        match(TokenType::ID);
    }
    else{
        if(peek()==TokenType::STRING){
            auto* parameter1 = new Parameter(inputTokens[index]->getDescription());
            predPtr->stringPredAdd(parameter1);
        }
        match(TokenType::STRING);
    }
}
void Datalog::parameterList(Predicate* predPtr) {
    //cout << "\t\tIn parameterList \n";
    if(peek()==TokenType::RIGHT_PAREN){
        return;
    }
    else{
        match(TokenType::COMMAS);
        parameter(predPtr);
        parameterList(predPtr);
    }
}
TokenType Datalog::peek(){
    inputTokens[index+1];
    return inputTokens[index]->getType();
}

vector<Predicate *> Datalog::GetSchemes() const {
    return schemes;
}
vector<Predicate *> Datalog::GetFacts() const {
    return facts;
}
//vector<Predicate *> Datalog::GetQueries() {
//    return queries;
//}
vector<P2Rules *> Datalog::GetRules() const {
    return rules;
}



