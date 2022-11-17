//
// Created by Ammon on 10/25/2022.
//

#ifndef PROJECT_1_INTERPRETER_H
#define PROJECT_1_INTERPRETER_H
#include "Datalog.h"
#include "Database.h"
#include "Predicate.h"
#include "P4Relations.h"
#include "P2Rules.h"

class Interpreter {
public:
    explicit Interpreter(Datalog* datalog){
        datalog1 = datalog;
        database = new Database();
    }
    Datalog* datalog1;
    Database* database;

    static vector<string> getParameters(Predicate* type) {
        vector<string> getParamsVec;
        for(Parameter* par : type->parameter){
            getParamsVec.push_back(par->parameterVal);
        }
        return getParamsVec;
    }

    void InterpretSchemes() const{
        for(Predicate* schemes : datalog1->GetSchemes()){
            vector<string> paramS = getParameters(schemes);
            auto* header = new Header(paramS);
            auto* relation = new P4Relations(schemes->getPredID(), header);
            //cout << relation(schemes->getPredID()) << endl << endl;
            database->mappedDatabase.insert({relation->getName(), relation});
            //cout << "\n\n\n\n " << paramS.at(0) << "\n\n\n\n\n";
        }
    }

    void InterpretFacts() const{
        for(Predicate* facts : datalog1->GetFacts()){
            vector<string> paramF = getParameters(facts);
            TupleP2 tuple(paramF);
            P4Relations* relation = database->mappedDatabase[facts->getPredID()];
            relation->tuplesRelation.insert(tuple);
        }
    }

    void InterpretRules() const{
        cout << "Rules Evaluation\n";
        int rulePlace = static_cast<int>(datalog1->rules.size());
        for (P2Rules *rules: datalog1->rules) {
            cout << rules->ruleToString() << endl;
            vector<P4Relations *> relations;
            for(auto pred : rules->getBodyPredicate()){
                relations.push_back(evaluatePredicate(pred, getParameters(datalog1->rules[rulePlace])));
            }
            while(relations.size() > 1){
                P4Relations anotherRelation = relations.at(0)->naturalJoin(*relations.at(1));
                relations.insert(relations.begin() + 2, &anotherRelation);
                relations.erase(relations.begin());
                relations.erase(relations.begin());
            }
            rulePlace--;
        }
        for (P2Rules *rules: datalog1->rules) {
            cout << rules->ruleToString() << endl;
        }
        cout << endl;
    }

    void InterpretQueries() const{
        cout << "Query Evaluation\n";
        for(int queryPlace = 0; queryPlace < static_cast<int>(datalog1->queries.size()); queryPlace++){
            if(queryPlace != 0){
                cout << '\n';
            }
            cout << datalog1->queries[queryPlace]->predToString() << "?";
            vector<string> para = getParameters(datalog1->queries[queryPlace]);
            P4Relations relation1 = evaluatePredicate(datalog1->queries[queryPlace], para);
            int tuplsIterator = static_cast<int>(relation1.tuplesRelation.size());
            if(!static_cast<int>(relation1.tuplesRelation.empty())){
                cout << " Yes (" << relation1.tuplesRelation.size() << ")";
                for(TupleP2 tupl : relation1.tuplesRelation){
                    tuplsIterator--;
                    for(int i = 0; i < static_cast<int>(tupl.values.size()); i++){
                        if(i == 0){
                            cout << '\n';
                        }
                        if(i == static_cast<int>(tupl.values.size())-1){
                            if(i == 0){
                                cout << "  " << relation1.getHeader()->attributes[i] << '=' << tupl.values[i];
                            }
                            else{
                                cout<< " " << relation1.getHeader()->attributes[i] << '=' << tupl.values[i];
                            }
                        }
                        else{
                            if(tupl.values.size() == 1){
                                cout << " " << relation1.getHeader()->attributes[i] << '=' << tupl.values[i];
                            }
                            else{
                                cout << "  " << relation1.getHeader()->attributes[i] << '=' << tupl.values[i] << ',';
                            }
                        }
                    }
                }
            }
            else{
                cout << " No";
            }
        }
    }
    P4Relations evaluatePredicate(Predicate *pPredicate, const vector<string>& pParameter) const{
        P4Relations relationToPred = *database->mappedDatabase[pPredicate->getPredID()];
        map<string, int> selection;
        int i = 0;
        vector<int> column;
        vector<string> attributeValues;
        for(string stringParam : pParameter){
            if(stringParam[0] == '\''){
                relationToPred = *relationToPred.SelectValue(i, stringParam);
            }
            else{
                if(selection.find(stringParam) != selection.end()){
                    relationToPred = *relationToPred.SelectIndex(selection[stringParam], i);
                }
                else{
                    selection.insert({stringParam, i});
                    column.push_back(i);
                    attributeValues.push_back(stringParam);
                }
            }
            i++;
        }
        relationToPred = *relationToPred.project(column);
        relationToPred = *relationToPred.rename(attributeValues);
        return relationToPred;
    }
};


#endif //PROJECT_1_INTERPRETER_H
