//
// Created by Antonio on 27/08/2016.
//

#include "buffered_stream.h"
char buffered_stream::sig_caracter() {
    char c;
    if(linea_vacia()){
        buffer_linea.clear();
        buffer_linea.str(sig_linea() + "\n");
    }
    return (char)buffer_linea.get();
}


bool buffered_stream::fin_archivo() const{
    return archivo.eof();
}

bool buffered_stream::linea_vacia(){
    return buffer_linea.tellg()==buffer_linea.str().size();
}

std::string buffered_stream::sig_linea() {
    std::string linea;
    std::getline(archivo,linea);
    return linea;
}

bool buffered_stream::eof(){
    return linea_vacia()&&archivo.eof();
}



