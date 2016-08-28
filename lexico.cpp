//
// Created by Antonio on 25/08/2016.
//

#include "lexico.h"
const char Lexico::longitud_fija[]={'+', '-', '/', '*', '=', '<', '>', '!', '|', '&', '(',')'
        ,';',' ', '\n','\t'};
const int Lexico::estados_aceptacion[]=
        {11,10,9,12,13,8,14,15,16,14};
bool Lexico::is_error() const{
    return error;
}
std::string Lexico::sig_simbolo() {
    estado = 0;
    skip_blank();
    simbolo="";
    continua = true;
    char car;
    while (continua)
    {
        car=lector_archivo.sig_caracter();
        int sig=sig_estado(estado,car);
        if(sig!=-1) avanza_estado(sig,car);
        else if(is_aceptacion(sig)){}
    }
    return simbolo;
}
bool Lexico::is_aceptacion(int estado)
{
    return std::count(std::begin(estados_aceptacion),std::end(estados_aceptacion),estado)>0;
}

void Lexico::skip_blank() {
    char car;
    while((car=lector_archivo.sig_caracter())!=' '&&car!='\t'&&car!=EOF){};
}


void Lexico::avanza_estado(int estado, char caracter) {
    this->estado=estado;
    simbolo.push_back(caracter);
}



