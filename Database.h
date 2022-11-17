//
// Created by Ammon on 10/21/2022.
//

#ifndef PROJECT_1_DATABASE_H
#define PROJECT_1_DATABASE_H

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "P4Relations.h"

using namespace std;

class Database{
public:
    map<string /*key*/, P4Relations* /*value*/> mappedDatabase;
};

#endif //PROJECT_1_DATABASE_H

