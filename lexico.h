//
// Created by Antonio on 25/08/2016.
//

#ifndef ANALIZADOR_LEXICO_LEXICO_H
#define ANALIZADOR_LEXICO_LEXICO_H

#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include "buffered_stream.h"
class Lexico {
    std::string simbolo;
    int estado;
    bool continua;
    bool error;
    bool is_error() const ;
    buffered_stream lector_archivo;
    static constexpr char longitud_fija[]={'+', '-', '/', '*', '=', '<', '>', '!', '|', '&', '(',')'
            ,';',' ', '\n','\t'};
    public:
    explicit Lexico(std::istream &archivo):simbolo(),estado(0),continua(false),error(false),lector_archivo(archivo) {}
    std::string sig_simbolo();

};


#endif //ANALIZADOR_LEXICO_LEXICO_H
