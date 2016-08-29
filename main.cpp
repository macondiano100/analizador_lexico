#include <iostream>
#include <fstream>
#include "lexico.h"
using namespace std;
int main()
{
    std::ifstream archivo("entrada.txt");
    std::ofstream salida("salida.txt");
    Lexico lexico(archivo);
    string simbolo;
    simbolo=lexico.sig_simbolo();
    bool error_lexico =false;
    while(!error_lexico&&simbolo[0]!=EOF)
    {
        error_lexico = lexico.is_error();
        cout<<"("<<simbolo<<")"<<(error_lexico?"error!":"")<<endl;
        simbolo=lexico.sig_simbolo();
    }
    salida<<(error_lexico?"0":"1");
}