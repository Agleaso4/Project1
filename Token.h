#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <sstream>
using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    ADD,
    COMMAS,
    PERIOD,
    MULTIPLY,
    LEFT_PAREN,
    RIGHT_PAREN,
    Q_MARK,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    FSA_EOF
};


class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    string description;
    int line;
    string tokenToString(TokenType T){
        switch(T){
            case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
            case TokenType::LEFT_PAREN: return "LEFT_PAREN";
            case TokenType::PERIOD: return "PERIOD";
            case TokenType::COMMAS: return "COMMA";
            case TokenType:: Q_MARK: return "Q_MARK";
            case TokenType:: ADD: return "ADD";
            case TokenType:: MULTIPLY: return "MULTIPLY";
            case TokenType:: COLON: return "COLON";
            case TokenType:: COLON_DASH: return "COLON_DASH";
            case TokenType:: QUERIES: return "QUERIES";
            case TokenType::RULES: return "RULES";
            case TokenType::SCHEMES: return "SCHEMES";
            case TokenType:: FACTS: return "FACTS";
            case TokenType::COMMENT: return "COMMENT";
            case TokenType::ID: return "ID";
            case TokenType:: STRING: return "STRING";
            case TokenType::UNDEFINED: return "UNDEFINED";
            case TokenType::FSA_EOF: return "EOF";
            default: return "error in token to string";
        }
    }

public:
    Token(TokenType type, string description, int line){
        // TODO: initialize all member variable
        this->type = type;
        this->description = description;
        this->line = line;
    }

    const string &getDescription() const {
        return description;
    }

    TokenType getType(){
        return type;
    }
    string toString() {
        stringstream ss;
        ss << "(" << tokenToString(type) << ",\"" << description << "\"," << line << ")";
        return ss.str();
    };
    //ToString method with the token
    // TODO: add other needed methods
};

#endif // TOKEN_H

