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
    buffered_stream lector_archivo;
    static const char longitud_fija[];
    static const int estados_aceptacion[];

    void skip_blank();
    int sig_estado(int estado_actual, char simbolo);
    void avanza_estado(int estado, char caracter);
    bool is_aceptacion(int estado);
    bool is_longitud_fija(int estado);
    void set_error(bool e);
    public:
    explicit Lexico(std::istream &archivo):simbolo(),estado(0),continua(false),error(false),lector_archivo(archivo) {}
    std::string sig_simbolo();
    bool is_error() const ;

};


#endif //ANALIZADOR_LEXICO_LEXICO_H
