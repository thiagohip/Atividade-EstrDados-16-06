#include <iostream>


class Banda
{
    public:
        Banda();
        Banda* inserir_banda(Banda*, std::string, std::string, double, double, int);
        void mostrar_bandas(Banda*);
        Banda* excluir_banda(Banda*);
        Banda* limpar_bandas(Banda*);
        std::string getNome();
        std::string getLocal();
        double getCache();
        double getValor();
        int getPublico();
        void dados_da_banda(Banda*);
        Banda *elo;
    protected:

    private:
        std::string nome, local;
        double cache, valor_do_ingresso;
        int public_pagante;
};
