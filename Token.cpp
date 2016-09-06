//
// Created by Antonio on 06/09/2016.
//

#include "Token.h"



Token::Token():Token(Tipo_Token::END,""){
}

Token::Token(const Token::Tipo_Token& tipo, const std::string& lexema):_tipo(tipo),_lexema(lexema) {
}

const Token::Tipo_Token &Token::tipo() const {
    return _tipo;
}

const std::string &Token::lexema() const {
    return _lexema;
}