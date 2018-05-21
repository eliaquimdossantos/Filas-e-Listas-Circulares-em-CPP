#ifndef FC_H
#define FC_H

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
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		novo->setNext(this->inicio);
		this->inicio = novo;
		this->tamanho++;

		auto atual = inicio;  /*!< Auxiliar para percorrer a lista */

		/** @brief Procura o ultimo valor da lista*/
		for(int i = 0; i < tamanho-1; i++){
			atual = atual->getNext(); 
		}

		this->final = atual; /*!< final recebe o endereço do último valor da lista */
		this->final->setNext(this->inicio); /*!< A cabeça da fila é definida como próximo valor após a final */

		return true;
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
bool FilaCircular<T>::Remover() {
	if(!vazia()){
		if (this->inicio==nullptr) return false;
		inicio = inicio->getNext();
		this->tamanho--;
		return true;
	}else
		return false;
}

template <typename T>
bool FilaCircular<T>::vazia() {
	return tamanho <= 0;
}

template <typename T>
int FilaCircular<T>::size() {
	return this->tamanho;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, FilaCircular<T> const &l) {
	auto atual = l.inicio;

	for(int i = 0; i < l.tamanho; i++){
		o << "Elemento " << i+1 << ":" <<atual->getValor() << endl;
		atual = atual->getNext();
	}		

	return o;
}

#endif