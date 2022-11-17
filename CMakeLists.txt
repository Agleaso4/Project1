cmake_minimum_required(VERSION 3.16)
project(Project_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(./Lab1PassOffCases/1-70, Lab1PassOffCases/1-90, Lab1PassOffCases/1-100, Lab2PassOffCases/2-80, Lab2PassOffCases/2-100)

add_executable(Project_1
        Automaton.h
        ColonAutomaton.h
        ColonDashAutomaton.h
        COMMAS.h
        PERIOD.h
        LEFT_PAREN.h
        RIGHT_PAREN.h
        MULTIPLY.h
        Q_MARK.h
        ADD.h
        SCHEMES.h
        FACTS.h
        RULES.h
        QUERIES.h
        ID.h
        STRING.h
        COMMENT.h
        Lexer.cpp
        Lexer.h
        Datalog.cpp
        Datalog.h
        Interpreter.h
        Database.h
        Tuple.h
        Header.h
        main.cpp
        Token.h)
