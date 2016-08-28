//
// Created by Antonio on 27/08/2016.
//

#ifndef ANALIZADOR_LEXICO_BUFFERED_STREAM_H
#define ANALIZADOR_LEXICO_BUFFERED_STREAM_H


#include <string>
#include <sstream>

class buffered_stream {
    std::istream &archivo;
    std::istringstream buffer_linea;
    std::string sig_linea();
    bool linea_vacia();
    bool fin_archivo()const;
public:
    explicit buffered_stream(std::istream& archivo): archivo(archivo){}
    operator bool() {
        return eof();
    }
    bool eof();
    char sig_caracter() ;
};


#endif //ANALIZADOR_LEXICO_BUFFERED_STREAM_H
