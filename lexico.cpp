//
// Created by Antonio on 25/08/2016.
//
#include <cctype>
#include "lexico.h"
const char Lexico::longitud_fija[]={'+', '-', '/', '*', '=', '<', '>', '!', '|', '&', '(',')'
        ,';',' ', '\n','\t','\"',EOF};
const int Lexico::estados_aceptacion[]=
        {1,2,4,6,11,10,9,12,13,8,14,15,16,14,20};
bool Lexico::is_error() const{
    return error;
}

int Lexico::sig_estado(int estado_actual, char simbolo) {
    int sig=-1;
    switch (estado_actual)
    {
        case 0:
            if(simbolo=='<'||simbolo=='>') sig=11;
            else if(simbolo=='=') sig=10;
            else if(simbolo=='!') sig=9;
            else if(simbolo=='+'||simbolo=='-')
                sig=12;
            else if(simbolo==';') sig=13;
            else if(simbolo=='*') sig=14;
            else if(simbolo=='/') sig=15;
            else if(simbolo==')'||simbolo=='(') sig=16;
            else if(simbolo=='|') sig=17;
            else if(simbolo=='&') sig=18;
            else if(simbolo=='\n') sig=20;
            else if(isalpha(simbolo)||simbolo=='_') sig=1;
            else if(simbolo=='"') sig=5;
            else if(isdigit(simbolo)) sig=2;
            break;
        case 1:
            if(isalnum(simbolo)||simbolo=='_') sig=1;
            break;
        case 2:
            if(isdigit(simbolo)) sig=2;
            else if(simbolo=='.') sig=3;
            break;
        case 3:
            if(isdigit(simbolo)) sig=4;
            break;
        case 4:
            if(isdigit(simbolo)) sig=4;
            break;
        case 5:
            if(simbolo!=EOF&&simbolo!='"') sig=5;
            else if(simbolo=='"') sig=6;
        case 11:
        case 9:
        case 10:
            if(simbolo=='=') sig=8;
            break;
        case 17:
            if(simbolo=='|') sig=19;
            break;
        case 18:
            if(simbolo=='&') sig=19;
            break;
        default:
            break;
    }
    return sig;
}

#include <iostream>
std::string Lexico::sig_simbolo() {
    estado = 0;
    skip_blank();
    simbolo="";
    continua = true;
    char car=lector_archivo.sig_caracter();
    if(car == EOF) simbolo=EOF;
    else{
        set_error(false);
        while (continua)
        {
            int sig=sig_estado(estado,car);
            if(sig!=-1)
            {
                avanza_estado(sig,car);
                car=lector_archivo.sig_caracter();
            }
            else{
                if(is_aceptacion(estado)&&
                        (is_longitud_fija(simbolo.back())//longitud fija puede estar "pegado" a cualquier cosa
                         ||isspace(car)||car==EOF||is_longitud_fija(car))){//longitud puede estar "pegado" a fijo
                    if(car!=EOF)
                        lector_archivo.retroceso();
                    continua = false;
                }
                else
                {
                    while (!is_longitud_fija(car)) {
                        simbolo += car;
                        car = lector_archivo.sig_caracter();
                    };
                    if(car!=EOF)lector_archivo.retroceso();
                    continua = false;
                    set_error(true);
                }
            }
        }
    }
    return simbolo;
}
void Lexico::set_error(bool e)
{
    error =e;
    if(e){
        estado = -1;
    }
}
bool Lexico::is_aceptacion(int estado)
{
    return std::count(std::begin(estados_aceptacion),std::end(estados_aceptacion),estado)>0;
}
bool Lexico::is_longitud_fija(int estado)
{
    return std::count(std::begin(longitud_fija),std::end(longitud_fija),estado)>0;
}
void Lexico::skip_blank() {
    char car;
    while((car=lector_archivo.sig_caracter())==' '||car=='\t'){};
    if(car!=EOF) lector_archivo.retroceso();
}


void Lexico::avanza_estado(int estado, char caracter) {
    this->estado=estado;
    simbolo.push_back(caracter);
}



