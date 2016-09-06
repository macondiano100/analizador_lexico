//
// Created by Antonio on 06/09/2016.
//

#ifndef ANALIZADOR_LEXICO_TOKEN_H
#define ANALIZADOR_LEXICO_TOKEN_H

#include <string>
class Token {

    enum class Tipo_Token;
    Tipo_Token _tipo;
    std::string _lexema;
public:
    Token();
    Token(const Tipo_Token &tipo, const std::string &lexema);
    const Tipo_Token& tipo() const;
    const std::string& lexema() const;

};

enum class Token::Tipo_Token{
    OP_REL,OP_ARIT,OP_LOG,PARENTESIS,SEMICOLON,ENTERO,REAL,
    IDENTIFICADOR,CADENA,SALTO,END
};



#endif //ANALIZADOR_LEXICO_TOKEN_H
