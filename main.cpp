#include <iostream>
#include "Banda.h"

using namespace std;

Banda* maior_plateia(Banda *T){
    Banda *aux = T;
    Banda *maior = T;
    while(aux->elo != NULL){
        if(aux->getPublico() > maior->getPublico()){
            maior = aux;
        }
        aux = aux->elo;
    }
    return maior;
}

Banda* maior_cache(Banda *T){
    Banda *aux = T;
    Banda *maior = T;
    while(aux->elo != NULL){
        if(aux->getCache() > maior->getCache()){
            maior = aux;
        }
        aux = aux->elo;
    }
    return maior;
}

Banda* maior_lucro(Banda *T){
    Banda *aux = T;
    Banda *maior = T;
    while(aux->elo != NULL){
        if((aux->getPublico()*aux->getValor())-aux->getCache() > (maior->getPublico()*maior->getValor())-maior->getCache()){
            maior = aux;
        }
        aux = aux->elo;
    }
    return maior;
}





int main()
{
    Banda *T = NULL;
    Banda *aux;
    string nome, local;
    double cache, valor_do_ingresso;
    int public_pagante, op;
    do{
        cout << "[1]Cadastrar show\n";
        cout << "[2]Excluir show\n";
        cout << "[3]Listagem geral\n";
        cout << "[4]Listar show com maior plateia\n";
        cout << "[5]Listar banda com maior cache\n";
        cout << "[6]Listar show com maior lucro\n";
        cout << "[7]Sair\n";
        cin >> op;

        switch(op){
            case 1:
                system("clear");
                cout << "Insira o nome da banda: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Insira o local do show: ";
                getline(cin, local);
                cout << "Insira o cache do artista: ";
                cin >> cache;
                cout << "Insira o valor do ingresso: ";
                cin >> valor_do_ingresso;
                cout << "Insira quantas pessoas compraram ingressos: ";
                cin >> public_pagante;
                T = T->inserir_banda(T, nome, local, valor_do_ingresso, cache, public_pagante);
                break;
            case 2:
                T = T->excluir_banda(T);
                break;
            case 3:
                T->mostrar_bandas(T);
                break;
            case 4:
                aux = maior_plateia(T);
                cout << "A banda com maior plateia foi: \n" << aux.getNome() << " - " << aux.getLocal() << endl;
                break;
            case 5:

            case 7:
                T = T->limpar_bandas(T);
                break;
        }

    }while(op != 7);
    return 0;
}
