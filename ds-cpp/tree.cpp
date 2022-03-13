// DEPTH of a p is a number of ancestors of p, excluding p itself.
// This implies that depth of the root T is 0.
//
// Depth of p's node can also be defined recursively
//  - If p is the root, then the depth of p is 0.
//  - Otherwise, depth of p is depth of a p's parent plus one.
//
//  Depth(T, p):
//      if p.IsRoot() then
//          return 0
//      else
//          return 1 + Depth(T, p.Parent())
//
//  HEIGHT of a node p in a tree T is also defined recursively.
//   - if p is a leaf, then the height of p is 0
//   - Otherwise, the height of p is one plus max height of a child of p
//
//   Height(T, p):
//      if p.IsExternal() then
//          return 0
//      else
//          h <- 0
//          for each q <- p.Children() do
//              h <- max(h, height(T, q))
//          return 1 + h
//
// ---------------------------------------------------------------------------
// A traversal of a tree T is a systematic way of accessing (visiting) all the 
// nodes of T. In preorder traversal of tree T the root of T is visited first
// and then the sub-tree rooted at its children are traversed recursively.
//
//  Preorder(T, p):
//      Visit(p)
//      for each q <- p.Children() do
//          Preorder(T, q)
//
// Postorder traversal can be viewed as an opposite of the preorder traversal.
// Because, it recursively traverses the subtrees rooted at the children of
// the root first and then visits the root.
//
//  Postorder(T, p):
//      for each q <- p.Children() do
//          Postorder(T, q)
//      Visit(p)
//
// ---------------------------------------------------------------------------
// Binary Tree
// 
// we denote depth as d. Binary tree with d level has at most 2^d nodes.
//

#include <iostream>
#include <list>

// int depth(const Tree& T, const Position& p) {
//     if p.isRoot()
//         return 0
//     return depth(T, p.parent()) + 1
// }
// 
// int height(const Tree& T, const Position& p) {
//     if (p.isLeaf())
//         return 0
//     else
//         int h = 0;
//         for (auto& q : p.children())
//             h = max(h, height(T, q));
//         return 1 + h;
// }
// 
// void preorderPrint(const Tree& T, const Position& p) {
//     std::cout << *p;
//     for (auto& q : p.children()) {
//         std::cout << " ";
//         preorderPrint(T, q);
//     }
// }
// 
// void postorderPrint(const Tree& T, const Position& p) {
//     for (auto& q : p.children()) {
//         postorderPrint(T, q);
//         std::cout << " ";
//     }
//     std::cout << *p;
// }

template <typename E>
struct Node {
protected:
    E elem;
    Node* parent;
    Node* left;
    Node* right;

    Node() : elem(), parent(nullptr), left(nullptr), right(nullptr) {}
    E& operator*();
};

template <typename E>
class Position {
private:
    Node<E>* v;

public:
    Position(Node<E>& _v = nullptr) : v(_v) {}

    E& operator*() {
        return v->elem;
    }

    Position left() const {
        return Position(v->left);
    }

    Position right() const {
        return Position(v->right);
    }

    Position parent() const {
        return Position(v->parent);
    }

    bool isRoot() const {
        return !v->parent;
    }

    bool isExternal() const {
        return !v->left && !v->right;
    }
};

typedef std::list<Position<int>> PositionList;

template <typename E>
class BinaryTree {
public:
    int size;
    Node<E> root;

    int size() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    Node& parent() const;
    NodeList children() const;
};


int main() {
    auto tree = BinaryTree<int>();
    return 0;
}
