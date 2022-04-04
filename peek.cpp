#include <iostream>
#include <vector>
#include <queue>


int main() {
    typedef std::priority_queue<int, std::vector<int>, std::greater<int>> MinPQ;
    MinPQ pq{};
    pq.push(43);
    pq.push(23);
    std::cout << pq.top() << std::endl;
    return 0;
}
