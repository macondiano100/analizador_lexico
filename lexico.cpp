//
// Created by Antonio on 25/08/2016.
//
#include <cctype>
#include "lexico.h"
const char Lexico::longitud_fija[]={'+', '-', '/', '*', '=', '<', '>', '!', '|', '&', '(',')'
        ,';',' ',',', '\n','\t',EOF};
const int Lexico::estados_aceptacion[]=
        {1,2,4,6,11,10,9,12,13,8,14,15,16,19,20,21};
bool Lexico::is_error() const{
    return error;
}
Token::Tipo_Token Lexico::get_tipo(int estado)
{
    using Tipo_Token=Token::Tipo_Token;
    Tipo_Token tipo;
    switch (estado)
    {
        case 1:tipo = Tipo_Token::IDENTIFICADOR;
            break;
        case 2:tipo = Tipo_Token::ENTERO;
            break;
        case 4:tipo = Tipo_Token::REAL;
            break;
        case 6:tipo = Tipo_Token::CADENA;
            break;
        case 8:
        case 11:
            tipo = Tipo_Token::OP_REL;
            break;
        case 10:
            tipo = Tipo_Token::OP_ASIGNACION;
            break;
        case 12:
            tipo = Tipo_Token::OP_SUMA;
            break;
        case 13:tipo = Tipo_Token::SEMICOLON;
            break;
        case 14:tipo = Tipo_Token::OP_MULT;
            break;
        case 15:tipo= Tipo_Token::OP_DIV;
            break;
        case 16:tipo= Tipo_Token::PARENTESIS_ABRE;
            break;
        case 19:tipo = Tipo_Token::OP_LOG;
            break;
        case 21: tipo = Tipo_Token::PARENTESIS_CIERRA;
            break;
        case 20:tipo = Tipo_Token::SALTO;
            break;
        default:
            tipo = Tipo_Token::UNKNOWN;
    }
    return tipo;
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
            else if(simbolo==';'||simbolo==',') sig=13;
            else if(simbolo=='*') sig=14;
            else if(simbolo=='/') sig=15;
            else if(simbolo=='(') sig=16;
            else if(simbolo==')') sig=21;
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
        case 9:
        case 10:
        case 11:
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
    set_error(false);
    if(car == EOF) {
        simbolo = EOF;
        token = Token();
    }
    else{
        while (continua)
        {
            int sig=sig_estado(estado,car);
            if(sig!=-1)
            {
                avanza_estado(sig,car);
                car=lector_archivo.sig_caracter();
            }
            else{
                if(
                        is_aceptacion(estado)&&
                        (is_longitud_fija(simbolo.back())//longitud fija puede estar "pegado" a cualquier cosa
                         ||isspace(car)||car==EOF||is_longitud_fija(car)||estado==6)//longitud puede estar "pegado" a fijo
                        )
                {
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
    token = Token(get_tipo(estado),simbolo);
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
    while((car=lector_archivo.sig_caracter())==' '||car=='\t'||car=='\r'){};
    if(car!=EOF) lector_archivo.retroceso();
}


void Lexico::avanza_estado(int estado, char caracter) {
    this->estado=estado;
    simbolo.push_back(caracter);
}

const Token &Lexico::operator*() {
    return token;
}

Lexico &Lexico::operator++() {
    sig_simbolo();
    return *this;
}

const Token &Lexico::operator++(int) {
    sig_simbolo();
    return token;
}

const Token *Lexico::operator->() {
    return &token;
}




