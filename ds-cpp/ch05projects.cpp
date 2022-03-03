#include <iostream>
#include <vector>

template<class E>
class DequeArray {
public:
    DequeArray()
        : elements(new E[20]), len(0) {}

    ~DequeArray() {
        delete[] elements;
    }

    void pushFront(E elem) {
        elements[0] = elem;
        len++;
    }

    void pushBack(E elem) {
        elements[len];
    }

    E& peekFront() {
    }

private:
    E* elements;
    size_t len;
};

int main() {
    {
        auto deque = DequeArray<int>();
        deque.pushFront(3);
        deque.pushFront(7);
        deque.pushFront(9);
        std::cout << deque.peekFront() << std::endl;
    }

    {
        auto deque = DequeArray<int>();
        deque.pushBack(3);
        deque.pushBack(7);
        deque.pushBack(9);
        std::cout << deque.peekFront() << std::endl;
    }
    return 0;
}
