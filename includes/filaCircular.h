#ifndef LCE_H
#define LCE_H

#include <memory>
#include <iostream>
#include "node.h"

using namespace std;
/* Implementacao da classe FilaCircular */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend eh preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class FilaCircular; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, FilaCircular<T> const & );
// --

template <typename T>
class FilaCircular {
private:
	shared_ptr<Node<T>> inicio;
	shared_ptr<Node<T>> final;
	int tamanho;
public:
	FilaCircular();
	~FilaCircular();
	bool Inserir(T _valor);
	bool Remover();
	bool vazia();
	int size();

	friend std::ostream& operator<< <T>( std::ostream&, FilaCircular<T> const &l);
};

template <typename T>
FilaCircular<T>::FilaCircular(): inicio(nullptr), final(nullptr), tamanho(0) {}

template <typename T>
FilaCircular<T>::~FilaCircular() {
	while (inicio != this->final)
		inicio = inicio->getNext();
}

template <typename T>
bool FilaCircular<T>::Inserir(T _valor) {


	if (this->inicio == nullptr) {
		return InsereNoInicio(_valor);
	} else {
		auto atual = this->inicio;

		for(int i = 0; i < tamanho-1; i++)
			atual = atual->getNext(); 
				
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		atual->setNext(novo);
		this->final = novo;
		final->setNext(this->inicio);
		this->tamanho++;
	}

	return true;
}

template <typename T>
bool FilaCircular<T>::RemoveNoFinal() {
	if (this->inicio==nullptr) return false;

	if (this->inicio->getNext()==this->final) {
		this->inicio = this->final;
		this->tamanho--;
		return true;
	}

	auto atual = this->inicio;
	while (atual->getNext()->getNext() != this->final)
		atual = atual->getNext();

	this->final = atual->getNext();
	atual->setNext(this->final);

	this->tamanho--;

	return true;
}

template <typename T>
bool FilaCircular<T>::vazia() {
	return tamanho == 0;
}

template <typename T>
int FilaCircular<T>::size() {
	return this->tamanho;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, FilaCircular<T> const &l) {
	auto atual = l.inicio;

	for(int i = 0; i < l.tamanho; i++){
		o << atual->getValor() << " ";
		atual = atual->getNext();
	}		

	return o;
}

#endif