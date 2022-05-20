#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(size_t size)
        : m_Size(size)
    {
        m_Nodes = std::vector<int>(size);
        for (size_t i = 0; i < size; i++)
            m_Nodes[i] = i;
    }

    int find(int node) const {
        return m_Nodes.at(node);
    }

    void unionSet(int x, int y) {
        int nodeX = find(x);
        int nodeY = find(y);
        if (nodeX != nodeY) {
            for (size_t i = 0; i < m_Size; i++) {
                if (m_Nodes[i] == nodeY)
                    m_Nodes[i] = nodeX;
            }
        }
    }

    bool connected(int x, int y) const {
        return find(x) == find(y);
    }

    void printUnion() const {
        for (size_t i = 0; i < m_Size; i++) {
            std::cout << m_Nodes.at(i) << " -> " << i << std::endl;
        }
    }

private:
    std::vector<int> m_Nodes;
    size_t m_Size;
};


class QuickUnionFind {
public:
    QuickUnionFind(size_t size)
        : m_Size(size)
    {
        m_Nodes = std::vector<int>(size);
        for (size_t i = 0; i < size; i++)
            m_Nodes[i] = i;
    }

    int find(int x) const {
        while (x != m_Nodes.at(x))
            x = m_Nodes.at(x);
        return x;
    }

    void unionSet(int x, int y) {
        int nodeX = find(x);
        int nodeY = find(y);
        if (nodeX != nodeY)
            m_Nodes[nodeY] = m_Nodes[nodeX];
    }

    bool connected(int x, int y) const {
        return find(x) == find(y);
    }

    void printUnion() const {
        for (size_t i = 0; i < m_Size; i++) {
            std::cout << m_Nodes.at(i) << " -> " << i << std::endl;
        }
    }

private:
    size_t m_Size;
    std::vector<int> m_Nodes;
};

int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    std::cout << std::boolalpha;
    QuickUnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    std::cout << uf.connected(1, 5) << std::endl;  // true
    std::cout << uf.connected(5, 7) << std::endl;  // true
    std::cout << uf.connected(4, 9) << std::endl;  // false


    // 1-2-5-6-7  3-8-9-4
    uf.unionSet(9, 4);
    std::cout << uf.connected(4, 9) << std::endl;  // true
    uf.printUnion();
                                                   //
    return 0;
}
