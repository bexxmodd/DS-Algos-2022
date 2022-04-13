#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>


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


int main() {
    std::unordered_set<int> visited{};
    if (has_path(graph, 2, 6, visited))
        std::cout << "Has Path" << std::endl;
    else
        std::cout << "No Path" << std::endl;

    std::cout << count_cc(graph) << std::endl;
    return 0;
}
