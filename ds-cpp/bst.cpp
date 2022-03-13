#include <iostream>
#include <assert.h>
#include <stack>
#include <queue>

template <class E>
struct Node {
    E val;
    Node* left;
    Node* right;

    Node()
        : val(NULL), left(nullptr), right(nullptr) {}

    Node(const E _val)
        : val(_val), left(nullptr), right(nullptr) {}

    Node(const E _val, const Node& _left, const Node& _right)
        : val(_val), left(_left), right(_right) {}
};

template <class E>
class BST {
public:
    Node<E>* root;
    int _size;

    BST()
        : root(nullptr), _size(0) {}

    BST(const E value)
        : root(new Node<E>(value)), _size(1) {}

    int size() const {
        return _size;
    }

    void insert(const E value) {
        insert(&root, value);
        _size++;
    }

    E min() const {
        assert(_size > 0);
        auto _p = root;
        for (; _p->left; _p = _p->left)
            ;
        return _p->val;
    }

    E max() const {
        assert(_size > 0);
        auto _p = root;
        for (; _p->right; _p = _p->right)
            ;
        return _p->val;
    }

    int height() const {
        return height(root);
    }

    void bfsPrint() const {
        if (!root)
            return;
        std::queue<Node<E>*> frontier{};
        frontier.push(root);
        while (!frontier.empty()) {
            auto p = frontier.front(); frontier.pop();
            std::cout << p->val << ", ";
            if (p->left)
                frontier.push(p->left);
            if (p->right)
                frontier.push(p->right);
        }
        std::cout << std::endl;
    }

protected:
    void insert(Node<E>** p, E e) {
        if (!*p)
            *p = new Node<E>(e);
        else if (e <= (*p)->val)
            insert(&(*p)->left, e);
        else 
            insert(&(*p)->right, e);
    }

    int height(Node<E>* p) const {
        if (!p)
            return -1;
        return std::max(height(p->left), height(p->right)) + 1;
    }
};

int main() {
    BST<char> tree{'F'};
    tree.insert('B');
    tree.insert('G');
    tree.insert('A');
    tree.insert('D');
    tree.insert('I');
    tree.insert('C');
    tree.insert('E');
    tree.insert('H');
    std::cout << "Tree size: " << tree.size() << std::endl;
    std::cout << "Min: " << tree.min() << std::endl;
    std::cout << "Max: " << tree.max() << std::endl;
    std::cout << "Tree height: " << tree.height() << std::endl;
    tree.bfsPrint();
    return 0;
}
