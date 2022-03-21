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

    BST(std::vector<E>& sortedVals) : _size(sortedVals.size()) {
        root = insertHelper(0, sortedVals.size() - 1, sortedVals);
    }

    int size() const {
        return _size;
    }

    void insert(const E value) {
        insert(&root, value);
        _size++;
    }

    void remove(const E value) {
        auto _ = remove(root, value);
    }

    Node<E>* minNode(Node<E>* p) const {
        if (!p)
            return nullptr;
        for (; p->left; p = p->left)
            ;
        return p;
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

    int depth() const {
        if (root)
            return maxDepth(root, 0);
        return 0;
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

    bool isBst() const {
        std::vector<E> values;
        inorder(root, values);
        for (unsigned long i = 1; i < values.size(); i++) {
            if (values[i - 1] > values[i])
                return false;
        }
        return true;
    }

    bool leaf(const Node<E>* p) const {
        return !p->left && !p->right;
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

    int depth(Node<E>* p) const {
        if (!p)
            return 0;
        int leftDepth = depth(p->left);
        int rightDepth = depth(p->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    int maxDepth(Node<E>* p, int depth) const {
        if (p->left)
            return maxDepth(p->left, depth + 1);
        else if (p->right)
            return maxDepth(p->right, depth + 1);
        else
            return depth;
    }

    void inorder(Node<E>* p, std::vector<E> values) const {
        if (!p) return;
        inorder(p->left, values);
        values.push_back(p->val);
        inorder(p->right, values);
    }

    int numChildren(const Node<E>* p) const {
        int count{};
        if (p->left)
            count++;
        if (p->right)
            count++;
        return count;
    }

    Node<E>* insertHelper(int left, int right, std::vector<int>& vals) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        auto* p = new Node<E>(vals[mid]);
        p->left = insertHelper(left, mid - 1, vals);
        p->right = insertHelper(mid + 1, right, vals);
        return p;
    }

    Node<E>* remove(Node<E>* p, E value) {
        if (!p) return nullptr;
        else if (p->val > value) p->left = remove(p->left, value);
        else if (p->val < value) p->right = remove(p->right, value);
        else {
            if (leaf(p)) {
                delete p;
            } else if (!p->left) {
                auto* tmp = p;
                p = p->right;
                delete tmp;
            } else if (!p->right) {
                auto* tmp = p;
                p = p->right;
                delete tmp;
            } else {
                auto* tmp = minNode(p->right);
                p->val = tmp->val;
                p->right = remove(p->right, value);
            }
        }
        return p;
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
    std::cout << "Tree depth: " << tree.depth() << std::endl;
    tree.bfsPrint();
    assert(tree.isBst());

    std::vector<int> arr { 1, 3, 5, 6, 12, 24, 30 };
    BST<int> treeOfInts(arr);
    assert(treeOfInts.size() == 7);
    treeOfInts.bfsPrint();

    treeOfInts.remove(6);
    treeOfInts.bfsPrint();
    return 0;
}
