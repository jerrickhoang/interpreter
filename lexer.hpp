//
//  lexer.hpp
//  interpreter
//
//  Created by Anh Hoang on 4/16/16.
//  Copyright © 2016 Anh Hoang. All rights reserved.
//

#ifndef lexer_hpp
#define lexer_hpp

#include <stdio.h>
#include "token.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <exception>

namespace lexer {
class IllegalCharacterException: public std::exception {
    virtual const char* what() const throw() {
        return "Illegal character";
    }
};
class Lexer {
public:
    Lexer(const std::string& fp);
    token::Token next();

private:
    const std::unordered_set<char> digits_ = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const std::unordered_set<char> letters_ = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    int32_t col_;
    std::string currentLine_;
    std::ifstream sourceFile_;
    char currentChar_;
    
    void checkNextChar(const char& target);
    token::Token eitherOr(const char& opt, const token::Token& first, const token::Token& second);
    char nextChar();
    bool isLetter(const char& ch);
    bool isDigit(const char& ch);
    std::string getTillNotInSet(std::unordered_set<char> s);
};
}

#endif /* lexer_hpp */
