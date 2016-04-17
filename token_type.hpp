//
//  token_type.hpp
//  interpreter
//
//  Created by Anh Hoang on 4/16/16.
//  Copyright © 2016 Anh Hoang. All rights reserved.
//

#ifndef token_type_h
#define token_type_h
namespace token {
enum class TokenType {
    // Binary operators.
    And,
    Or,
    Plus,
    Minus,
    Multiply,
    Divide,
    NotEqual,
    Greater,
    GreaterOrEqual,
    Less,
    LessOrEqual,
    Equals,
    Assign,
    
    // Unary operators.
    Not,
    
    // Primitive types
    Bool,
    True,
    False,
    Char,
    Int,
    Float,
    Void,
    
    // Control keywords.
    If,
    Else,
    While,
    Return,
    
    // Special characters.
    Eof,
    LParen,
    RParen,
    LBracket,
    RBracket,
    LBrace,
    RBrace,
    Comma,
    SemiColon,
    
    // Variables.
    Identifier,
    IntLiteral,
    FloatLiteral,
    CharLiteral
};
}
#endif /* token_type_h */
