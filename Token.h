//
// Created by Antonio on 06/09/2016.
//

#ifndef ANALIZADOR_LEXICO_TOKEN_H
#define ANALIZADOR_LEXICO_TOKEN_H

#include <string>
class Token {

public:
    enum class Tipo_Token;
    Token();
    Token(const Tipo_Token &tipo, const std::string &lexema);
    const Tipo_Token& tipo() const;
    const std::string& lexema() const;
private:
    Tipo_Token _tipo;
    std::string _lexema;

};

enum class Token::Tipo_Token{
    OP_REL,OP_SUMA,OP_LOG,SEMICOLON,ENTERO,REAL,
    IDENTIFICADOR,CADENA,SALTO,END, OP_ASIGNACION, OP_MULT, OP_DIV, PARENTESIS_ABRE, PARENTESIS_CIERRA, UNKNOWN
};



#endif //ANALIZADOR_LEXICO_TOKEN_H
