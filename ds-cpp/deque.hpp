#include "ch03.hpp"

template<class T>
class Deque {
public:
    Deque() : elements(new DLinkedList<T>()) {}
    void pushFront(const T& elem) {
        elements.addFront(elem);
    }

    void pushBack(const T& elem) {
        elements.addBack(elem);
    }

    void peekFront() {
        elements.fonrt();
    }

    void peekBack() {
        elements.back();
    }

private:
    DLinkedList<T> elements;
};
