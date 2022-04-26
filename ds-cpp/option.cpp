#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
union Option {
    void* None;
    T value;

    Option(T _val)
        : value(_val) {}
    Option()
        : None(nullptr) {}
};

Option<int> getWinner(const std::vector<int>& res) {
    if (res.empty())
        return Option<int>();
    return res.at(1);
}

int main() {
    auto r = getWinner({ 1, 2, 3 });
    std::cout << r.value << std::endl;
    auto empty = getWinner({});
    assert(empty.None == nullptr);
    return 0;
}
