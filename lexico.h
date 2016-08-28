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
    std::string simbolo;
    int estado;
    bool continua;
    bool error;
    bool is_error() const ;
    public:
    explicit Lexico(std::istream &archivo):simbolo(),estado(0),continua(false),error(false) {}

};


#endif //ANALIZADOR_LEXICO_LEXICO_H
