#ifndef NODE_H
#define NODE_H

/* Implementacao da classe Node */

// Para permitir sobrecarregar o operador de insercao
// numa classe template como friend eh preciso adicionar
// o trecho de codigo a seguir
template <typename T> class Node; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Node<T> const & );
// --

template <typename T>
class Node
{
private:
	T valor;
	std::shared_ptr<Node<T>> proximo;
public:
	Node();
	Node(T _valor);
	~Node();
	Node(T num, std::shared_ptr<Node> nextPtr);
	T getValor();
	std::shared_ptr<Node<T>> getNext();
	void setNext(std::shared_ptr<Node<T>> nextPtr);

	friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
};

template <typename T>
Node<T>::Node() : valor(), proximo(nullptr) {}

template <typename T>
Node<T>::Node(T _valor) : valor(_valor), proximo(nullptr) {}

template <typename T>
Node<T>::~Node() {
	//std::cout << "Node(" << valor << ") removido." << std::endl;
}

template <typename T>
Node<T>::Node(T _valor, std::shared_ptr<Node<T>> nextPtr) : valor(_valor), proximo(nextPtr) {}

template <typename T>
T Node<T>::getValor() {
	return valor;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNext() {
	return proximo;
}

template <typename T>
void Node<T>::setNext(std::shared_ptr<Node<T>> nextPtr) {
	proximo = nextPtr;
}

template <typename T>
std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
	o << n.valor;
	return o;
}

#endif