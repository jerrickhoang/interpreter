//
//  token.cpp
//  interpreter
//
//  Created by Anh Hoang on 4/16/16.
//  Copyright © 2016 Anh Hoang. All rights reserved.
//

#include "token.hpp"

namespace token {
    Token Token::makeFloatLiteral(std::string name) {
        return Token(TokenType::FloatLiteral, name);
    }
    
    Token Token::makeIdentifier(std::string name) {
        return Token(TokenType::Identifier, name);
    }
    
    Token Token::makeIntLiteral(std::string name) {
        return Token(TokenType::IntLiteral, name);
    }
}