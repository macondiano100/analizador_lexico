//
// Created by Antonio on 25/08/2016.
//

#include "lexico.h"
char Lexico::sig_caracter() {
    char c;
    if(linea_vacia()){
        buffer_linea.clear();
        buffer_linea.str(sig_linea());
    }
    return buffer_linea.get();
}
bool Lexico::is_error() const{
    return error;
}

bool Lexico::fin_archivo() {
    return archivo.eof();
}

bool Lexico::linea_vacia() {
    return buffer_linea.tellg()==buffer_linea.str().size();
}

std::string Lexico::sig_linea() {
    std::string linea;
    std::getline(archivo,linea);
    return linea;
}