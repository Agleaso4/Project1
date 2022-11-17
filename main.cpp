#include "Lexer.h"
#include "Datalog.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>

using namespace std;

int main([[maybe_unused]] int argc, char** argv) {

    ifstream input(argv[1]);
    if (!input.is_open()) {
        cout << "File " << argv[1] << " could not be found or opened." << endl;
        return 1;
    }

    string output, line;
    while(getline(input, line))
    {
        output += line + '\n';
    }

    auto* lexer = new Lexer(output);
    auto* datalog = new Datalog();
    datalog->parser(lexer->getTokens());
    auto* interpreter = new Interpreter(datalog);
    interpreter->InterpretSchemes();
    interpreter->InterpretFacts();
    interpreter->InterpretRules();
    interpreter->InterpretQueries();

    // TODO

    delete lexer;

    return 0;
}
