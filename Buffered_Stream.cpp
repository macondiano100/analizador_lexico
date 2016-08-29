//
// Created by Antonio on 27/08/2016.
//

#include "Buffered_Stream.h"
char buffered_stream::sig_caracter() {
    if(linea_vacia()){
        guardar_sig_linea();
    }
    return (char)buffer_linea.get();
}

#include <iostream>
void buffered_stream::guardar_sig_linea()
{
    buffer_linea.clear();
    std::string linea=sig_linea();
    archivo.unget();
    if(archivo.get()=='\n')
    {
        linea+='\n';
    }
    buffer_linea.str(linea);
}
void buffered_stream::retroceso()
{
    if(!buffer_linea.unget()){
        //retroceder linea actual
        buffer_linea.clear();
        archivo.clear();
        archivo.seekg(-((int)buffer_linea.str().size()),archivo.cur);
        //retroceder linea anterior
        archivo.unget();
        while(archivo.unget()&&archivo.peek()!='\n') {}
        if(archivo.peek()=='\n')archivo.get();
        else archivo.clear();
        guardar_sig_linea();
        buffer_linea.seekg(-1,buffer_linea.end);
    }
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
    return linea_vacia()&&fin_archivo();
}



