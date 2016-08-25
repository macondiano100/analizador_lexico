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
class Lexico {
    std::istream &archivo;
    std::istringstream buffer_linea;
    std::string simbolo;
    int estado;
    bool continua;
    bool error;

    std::string sig_linea();;
    bool linea_vacia();
    bool fin_archivo();
    bool is_error() const ;
    char sig_caracter() ;
    public:
    explicit Lexico(std::istream &archivo):archivo(archivo),buffer_linea(),simbolo(),
                                                estado(0),continua(false),error(false) {}

};


#endif //ANALIZADOR_LEXICO_LEXICO_H
