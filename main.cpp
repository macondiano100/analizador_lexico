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
    simbolo=(++lexico)->lexema();
    bool error_lexico =false;
    while(!error_lexico&&lexico->tipo()!=Token::Tipo_Token::END)
    {
        error_lexico = lexico.is_error();
        cout<<"("<<simbolo<<")"<<(error_lexico?"error!":"")
            <<"<"<< static_cast<int>(lexico->tipo())<<">"<<endl;
        simbolo=(++lexico)->lexema();
    }
    salida<<(error_lexico?"0":"1");
}