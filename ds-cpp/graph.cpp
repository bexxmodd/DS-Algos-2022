#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>


typedef std::unordered_map<int, std::vector<int>> Graph;

Graph graph {
    {1, { 2, 3 }},
    {2, { 1 }},
    {3, { 1, 4, 6 }},
    {4, { 3 }},
    {6, { 3 }},
    {8, { 5 }},
    {5, { 8 }}
};

bool has_path(
        Graph& graph, const int src, const int dst,
        std::unordered_set<int>& visited
    ) {
    if (src == dst)
        return true;
    for (auto neighbor : graph[src]) {
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            if (has_path(graph, neighbor, dst, visited))
                return true;
        }
    }
    return false;
}

int count_cc(Graph& graph) {
    int count{};
    std::unordered_set<int> visited{};
    for (auto node : graph) {
        std::stack<int> st{};
        if (visited.find(node.first) == visited.end()) {
            st.push(node.first);
            while (!st.empty()) {
                int cur = st.top(); st.pop();
                for (int neighbor : graph[cur]) {
                    if (visited.find(neighbor) == visited.end()) {
                        count++;
                        visited.insert(neighbor);
                        st.push(neighbor);
                    }
                }
            }
        }
    }
    return count;
}

std::vector<std::pair<int, int>> neighbors(
        Graph& graph,
        std::pair<int, int>& loc
        ) {
    return {};
}

int shortest_path(
        Graph& graph,
        std::pair<int, int>& src,
        std::pair<int, int>& dst
    ) {
    using Queue = std::queue<std::pair<std::pair<int, int>, int>>;
    std::set<std::pair<int, int>> visited{};
    Queue frontier{};
    frontier.push({ src, 0 });
    while (!frontier.empty()) {
        std::pair<int, int> cell;
        int dist;
        std::tie(cell, dist) = frontier.front(); frontier.pop();
        if (cell.first == dst.first && cell.second == dst.second)
            return dist;

        for (auto& neighbor : neighbors(graph, cell)) {
            if (visited.count(neighbor) == 0) {
                frontier.push({ neighbor, dist + 1 });
                visited.insert(neighbor);
            }
        }
    }
    return -1;
}

struct pair_hash {
    template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
};

int main() {
    std::unordered_set<int> visited{};
    if (has_path(graph, 2, 6, visited))
        std::cout << "Has Path" << std::endl;
    else
        std::cout << "No Path" << std::endl;

    std::cout << count_cc(graph) << std::endl;

    std::unordered_map<std::pair<int, int>, int> umap{};
    std::unordered_set<std::pair<int, int>> uset{};
    std::map<std::pair<int, int>, int> omap{};
    std::set<std::pair<int, int>> oset{};

    return 0;
}
