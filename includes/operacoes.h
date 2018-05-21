#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include "filaCircular.h"
#include "listaLigadaCircular.h"

template <typename T> class Operacoes;

template <typename T>
class Operacoes{
private:
	ListLigCirc<T>  listLigCir;
	FilaCircular<T> filCirc;

	void menuFila();
	void menuLista();
public:
	Operacoes();
	~Operacoes();
	void menuPrincipal();
	void setFila();
	void setLista();
	ListLigCirc<T>  getLista();
	FilaCircular<T> getFila();
};

#include "operacoes.h"

using namespace std;

template <typename T>
Operacoes<T>::Operacoes(){

}

template <typename T>
Operacoes<T>::~Operacoes(){

}

template <typename T>
void Operacoes<T>::menuPrincipal(){
	short op;
	
	do{
		cout << endl;
		cout << "Digite '1' para manipular uma Fila Circular" << endl;
		cout << "Digite '2' para manipular uma Lista Encadeada Circular" << endl;
		cout << "Digite '3' para voltar" << endl;
		cout << endl;
		cout << ">Opção: ";
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				menuFila();
			break;
			case 2:
				menuLista();
			break;
			case 3:
				break;				
			}

		if(op != 1 && op != 2 && op != 3) cout << "Operação inválida" << endl;

	}while(op != 3);
}

template <typename T>
void Operacoes<T>::menuFila(){
	short op;
	T valor;

	do{
		cout << endl;
		cout << "Digite '1' para adicionar um elemento" << endl;
		cout << "Digite '2' para remover um elemento" << endl;
		cout << "Digite '3' para verificar se a fila está vazia" << endl;
		cout << "Digite '4' para verificar o tamanho" << endl;
		cout << "Digite '5' para imprimir o conteúdo da lista" << endl;
		cout << "Digite '6' para voltar" << endl;		
		cout << endl;
		cout << ">Opção: ";
		
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				cout << "Conteúdo: ";
				cin.ignore();
				getline(cin, valor);
				filCirc.Inserir(valor);
			break;
			case 2:
				filCirc.Remover();
			break;
			case 3:
				if(filCirc.vazia()) cout << "-Fila vazia" << endl;
				else cout << "-Fila não vazia" << endl;
			break;
			case 4:
				cout << "-Tamanho: " << filCirc.size() << endl;
				break;
			case 5:
				cout << filCirc << endl;
		}

		if(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6) 
			cout << "Operação inválida" << endl;

	}while(op != 6);	
}

template <typename T>
void Operacoes<T>::menuLista(){

}

template <typename T>
ListLigCirc<T> Operacoes<T>::getLista(){
	return listLigCir;
}

template <typename T>
FilaCircular<T> Operacoes<T>::getFila(){
	return filCirc;
}

#endif

