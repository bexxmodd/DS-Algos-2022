#include <set>
#include <iostream>
#include <functional>

int main() {
    std::string a = "twentyfour";
    std::hash<std::string> i_hash;
    std::cout << "a has hash: " << i_hash(a) << std::endl;

    std::set<int> s{};
    s.insert(5);
    s.insert(3);
    s.insert(4);
    s.insert(7);
    s.insert(2);
    s.insert(1);
    s.insert(8);
    s.insert(9);

    for (auto i : s)
        std::cout << i << ", ";
    std::cout << std::endl;
    std::cout << *s.begin() << std::endl;
    s.erase(s.begin());
    std::cout << *s.begin() << std::endl;
    return 0;
}
