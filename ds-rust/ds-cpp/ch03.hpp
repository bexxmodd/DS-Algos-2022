// Singly Linked List

template<typename T>
class LinkedList;

template<typename T>
class Node {
private:
    T elem;
    Node<T>* next;

    friend class LinkedList<T>;
};

template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const T front() const;    // get front element
    void addFront(const T& elem);
    void removeFront();

private:
    Node<T>* head;
};


