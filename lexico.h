//
// Created by Antonio on 25/08/2016.
//

#ifndef ANALIZADOR_LEXICO_LEXICO_H
#define ANALIZADOR_LEXICO_LEXICO_H
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Buffered_Stream.h"
#include "Token.h"
class Lexico: public std::iterator<std::input_iterator_tag,Token,void,const Token*,const Token&> {
    static const char longitud_fija[];
    static const int estados_aceptacion[];

    std::string simbolo;
    int estado;
    bool continua;
    bool error;
    buffered_stream lector_archivo;
    Token token;

    void skip_blank();
    int sig_estado(int estado_actual, char simbolo);
    void avanza_estado(int estado, char caracter);
    bool is_aceptacion(int estado);
    bool is_longitud_fija(int estado);
    void set_error(bool e);
    Token::Tipo_Token get_tipo(int);

    public:
    explicit Lexico(std::istream &archivo):simbolo(),estado(0),continua(false),error(false),lector_archivo(archivo)
            ,token() {}
    std::string sig_simbolo();
    bool is_error() const ;

    reference operator *();
    Lexico& operator ++(); //prefix
    reference operator ++(int);
    pointer operator ->();


};


#endif //ANALIZADOR_LEXICO_LEXICO_H
