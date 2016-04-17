//
//  token.hpp
//  interpreter
//
//  Created by Anh Hoang on 4/16/16.
//  Copyright © 2016 Anh Hoang. All rights reserved.
//

#ifndef token_hpp
#define token_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>
#include "token_type.hpp"
namespace token {

class Token {

// TODO(ahoang): is there a way to make this private to this file?
public:
    Token(TokenType type, std::string name);
    static Token makeIntLiteral(std::string name);
    static Token makeFloatLiteral(std::string name);
    static Token makeIdentifier(std::string name);
private:
    TokenType type_;
    std::string name_;
};

const Token TokenAnd            = Token(TokenType::And,            "&&"   );
const Token TokenOr             = Token(TokenType::Or,             "||"    );
const Token TokenPlus           = Token(TokenType::Plus,           "+"     );
const Token TokenMinus          = Token(TokenType::Minus,          "-"     );
const Token TokenMultiply       = Token(TokenType::Multiply,       "*"     );
const Token TokenDivide         = Token(TokenType::Divide,         "/"     );
const Token TokenNotEqual       = Token(TokenType::NotEqual,       "!="    );
const Token TokenGreater        = Token(TokenType::Greater,        ">"     );
const Token TokenGreaterOrEqual = Token(TokenType::GreaterOrEqual, ">="    );
const Token TokenLess           = Token(TokenType::Less,           "<"     );
const Token TokenLessOrEqual    = Token(TokenType::LessOrEqual,    "<="    );
const Token TokenEquals         = Token(TokenType::Equals,         "=="    );
const Token TokenAssign         = Token(TokenType::Assign,         "="     );
const Token TokenNot            = Token(TokenType::Not,            "!"     );
const Token TokenBool           = Token(TokenType::Bool,           "bool"  );
const Token TokenTrue           = Token(TokenType::True,           "true"  );
const Token TokenFalse          = Token(TokenType::False,          "false" );
const Token TokenChar           = Token(TokenType::Char,           "char"  );
const Token TokenInt            = Token(TokenType::Int,            "int"   );
const Token TokenFloat          = Token(TokenType::Float,          "float" );
const Token TokenVoid           = Token(TokenType::Void,           "void"  );
const Token TokenIf             = Token(TokenType::If,             "if"    );
const Token TokenElse           = Token(TokenType::Else,           "else"  );
const Token TokenWhile          = Token(TokenType::While,          "while" );
const Token TokenReturn         = Token(TokenType::Return,         "return");
const Token TokenEof            = Token(TokenType::Eof,            "eof"   );
const Token TokenLParen         = Token(TokenType::LParen,         "("     );
const Token TokenRParen         = Token(TokenType::RParen,         ")"     );
const Token TokenLBracket       = Token(TokenType::LBracket,       "["     );
const Token TokenRBracket       = Token(TokenType::RBracket,       "]"     );
const Token TokenLBrace         = Token(TokenType::LBrace,         "{"     );
const Token TokenRBrace         = Token(TokenType::RBrace,         "}"     );
const Token TokenComma          = Token(TokenType::Comma,          ","     );
const Token TokenSemiColon      = Token(TokenType::SemiColon,      ";"     );
    
const std::unordered_map<std::string, const Token&> keywordsMap = {
    {"bool"  , TokenBool},
    {"true"  , TokenTrue},
    {"false" , TokenFalse},
    {"char"  , TokenChar},
    {"int"   , TokenInt},
    {"float" , TokenFloat},
    {"void"  , TokenVoid},
    {"if"    , TokenIf},
    {"else"  , TokenElse},
    {"while" , TokenWhile},
    {"return", TokenReturn}
};

}

#endif /* token_hpp */
