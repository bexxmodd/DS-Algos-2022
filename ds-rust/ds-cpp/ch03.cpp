// Singly Linked List
#include "ch03.hpp"

template<typename T>
LinkedList<T>::LinkedList(): head(nullptr) { }

template<typename T>
LinkedList<T>::~LinkedList() {
    while (!empty())
        removeFront();
}

template<typename T>
bool LinkedList<T>::empty() const {
    return !head;
}

template<typename T>
const T LinkedList<T>::front() const {
   return head->elem; 
}

template<typename T>
void LinkedList<T>::addFront(const T& elem) {
    auto* v = new Node<T>;
    v->elem = elem;
    v->next = head;
    head = v;
}

template<typename T>
void LinkedList<T>::removeFront() {
    auto* old = head;
    head = old->next;
    delete old;
}
