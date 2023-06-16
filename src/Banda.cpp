#include "Banda.h"
#include "stdio"

Banda::Banda()
{
    //ctor
}


Banda* Banda::inserir_banda(Banda *T, std::string nome, std::string local, double valor_do_ingresso, double cache, int publico_pagante){
    Banda *aux = new Banda();
    aux->cache = cache;
    aux->local = local;
    aux->nome = nome;
    aux->public_pagante = publico_pagante;
    aux->valor_do_ingresso = valor_do_ingresso;
    aux->elo = T;
    return aux;
};

void Banda::dados_da_banda(Banda *T){

}

void Banda::mostrar_bandas(Banda *T){
    Banda *aux = T;
    if(aux == NULL){
        std::cout << "\nNenhuma banda cadastrada!\n";
    }else{
        std::cout << "\nBandas cadastradas:\n";
        while(aux != NULL){
            std::cout << aux->nome << std::endl;
            aux = aux->elo;
        }
    }
};

Banda* Banda::excluir_banda(Banda *T){
    Banda *aux = T->elo;
    delete (T);
    return aux;
}

Banda* Banda::limpar_bandas(Banda *T){
    Banda *aux = T;
    while(aux != NULL){
        T = T->elo;
        delete(aux);
        aux = T;
    }
    return T;
}

std::string Banda::getNome(){
    return this->nome;
}

std::string Banda::getLocal(){
    return this->local;
}

double Banda::getCache(){
    return this->cache;
}

double Banda::getValor(){
    return this->valor_do_ingresso;
}

int Banda::getPublico(){
    return this->public_pagante;
}

