// Singly Linked List
#include <cstdlib>

template<typename T>
class DLinkedList;

template<typename T>
class DNode {
private:
    T elem;
    DNode<T>* prev;
    DNode<T>* next;

    friend class DLinkedList<T>;
};

template<typename T>
class DLinkedList {
public:
    DLinkedList() {
        head = new DNode<T>; 
        tail = new DNode<T>; 
        head->next = nullptr;
        tail->prev = nullptr;
    }

    ~DLinkedList() {
        while (!empty())
            removeFront();
        delete head;
        delete tail;
    }

    bool empty() const {
        return head->next == tail;
    }

    const T& front() const {
        return head->next->elem;
    }

    const T& back() const {
        return tail->prev->elem;
    }

    void addFront(const T& elem) {
        add(head->next, elem);
    }

    void addBack(const T& elem) {
        add(tail, elem);
    }

    void removeFront() {
        remove(head->next);
    }

    void removeBack() {
        remove(tail->prev);
    }

    void reverse(DLinkedList& dlist) {
        DLinkedList tmp;
        while (!tmp.empty()) {
            T val = dlist.front();
            dlist.removeFront();
            tmp.addFront(val);
        }

        while (!tmp.empty()) {
            T val = tmp.front();
            tmp.removeFront();
            dlist.addBack(val);
        }
    }

protected:
    void add(DNode<T>* _v, const T* _e) {
        auto* new_node = new DNode<T>;
        new_node->elem = _e;
        new_node->next = _v;
        new_node->prev = _v->prev;
        _v->prev->next = _v->prev = new_node;
    }

    void remove(DNode<T>* _v) {
        auto* prev = _v->prev;
        auto* next = _v->next;
        prev->next = next;
        next->prev = prev;
        delete _v;
    }

private:
    DNode<T>* head;
    DNode<T>* tail;
    size_t length;
};


