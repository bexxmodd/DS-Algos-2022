#include <iostream>

template <class E>
struct Node {
    E element;
    Node<E>* left;
    Node<E>* right;

    Node(const E elem) : element(elem), left(nullptr), right(nullptr) { }

    bool leaf() const {
        return !left && !right;
    }
};

template <class E>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr), size(0) {}
    ~BinarySearchTree() {
        delete root;
        size = 0;
    }

    E& get_root() const {
        return root->element;
    }

    void add(const E elem) {
        auto v = root;
        __add(v, elem);
        size++;
    }


    void postorderPrint() {
        __postorderPrint(root);
    }


private:
    Node<E>* root;
    int size;

    void __postorderPrint(Node<E>* p) const {
        if (!p) {
            return;
        }
        __postorderPrint(p->left);
        __postorderPrint(p->right);
        std::cout << p->element << ", " << std::endl;
    }

    void __add(Node<E>* p, const E elem) {
        if (!p) {
            p = new Node<E>(elem);
        } else if (elem < p->element) {
            if (p->left)
                __add(p->left, elem);
            else
                p->left = new Node<E>(elem);
        } else {
            if (p->right)
                __add(p->right, elem);
            else
                p->right = new Node<E>(elem);
        }
    }
};

int main() {
    BinarySearchTree<int> tree{};
    tree.add(4);
    tree.add(3);
    tree.add(7);

    tree.postorderPrint();
    std::cout << "all done!" << std::endl;
    return 0;
}
