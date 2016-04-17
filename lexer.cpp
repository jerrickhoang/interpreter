//
//  lexer.cpp
//  interpreter
//
//  Created by Anh Hoang on 4/16/16.
//  Copyright © 2016 Anh Hoang. All rights reserved.
//

#include "lexer.hpp"


namespace lexer {
    Lexer::Lexer(const std::string& fp) {
        sourceFile_.open(fp);
    }
    
    char Lexer::nextChar() {
        col_++;
        if (col_ > currentLine_.size()) {
            if(!getline(sourceFile_, currentLine_)) {
                return NULL;
            }
            col_ = 0;
        }
        return currentLine_[col_];
    }
    
    token::Token Lexer::next() {
        do {
            if (isLetter(currentChar_)) {
                std::string word = getTillNotInSet(letters_);
                if (token::keywordsMap.find(word) != token::keywordsMap.end()) {
                    return token::keywordsMap.find(word)->second;
                }
                return token::Token::makeIdentifier(getTillNotInSet(letters_));
            }
            else if (isDigit(currentChar_)) {
                std::string number = getTillNotInSet(digits_);
                currentChar_ = nextChar();
                if (currentChar_ != '.') {
                    return token::Token::makeIntLiteral(number);
                }
                return token::Token::makeFloatLiteral(number + '.' + getTillNotInSet(digits_));
            }
            switch (currentChar_) {
                case '&':
                    checkNextChar('&');
                    return token::TokenAnd;
                case '|':
                    checkNextChar('|');
                    return token::TokenOr;
                case '+':
                    return token::TokenPlus;
                case '-':
                    return token::TokenMinus;
                case '*':
                    return token::TokenMultiply;
                case '/':
                    currentChar_ = nextChar();
                    if (currentChar_ != '/') {
                        return token::TokenDivide;
                    } else {
                        // Comment section.
                        do {
                            currentChar_ = nextChar();
                        } while (currentChar_ != '\n');
                    }
                case '!':
                    return eitherOr('=', token::TokenNotEqual, token::TokenNot);
                case '>':
                    return eitherOr('=', token::TokenGreaterOrEqual, token::TokenGreater);
                case '<':
                    return eitherOr('=', token::TokenLessOrEqual, token::TokenLess);
                case '=':
                    return eitherOr('=', token::TokenEquals, token::TokenAssign);
                case '(':
                    return token::TokenLParen;
                case ')':
                    return token::TokenRParen;
                case '[':
                    return token::TokenLBracket;
                case ']':
                    return token::TokenRBracket;
                case '{':
                    return token::TokenRBracket;
                case '}':
                    return token::TokenRBracket;
                case ',':
                    return token::TokenComma;
                case ';':
                    return token::TokenSemiColon;
            }
        } while (true);
    }
    
    void Lexer::checkNextChar(const char &target) {
        currentChar_ = nextChar();
        if (currentChar_ != target) {
            throw new IllegalCharacterException();
        }
    }

    token::Token Lexer::eitherOr(const char &opt, const token::Token &first, const token::Token &second) {
        currentChar_ = nextChar();
        return currentChar_ == opt? first : second;
    }
    
    std::string Lexer::getTillNotInSet(std::unordered_set<char> s) {
        std::string res = "";
        do {
            res += currentChar_;
            currentChar_ = nextChar();
        } while (s.find(currentChar_) != s.end());
        return res;
    }
}
int main() {
    std::string line;
    lexer::Lexer lex ("/Users/ahoang/workspace/interpreter/interpreter/test");
    //while(char c = lex.nextChar()) {
    //    std::cout << c << std::endl;
    //}
    return 0;
}