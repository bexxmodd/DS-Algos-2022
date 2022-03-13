#include <iostream>
#include <vector>

template<class T>
void bubbleSort(std::vector<T>& S) {
    size_t n = S.size();
    for (size_t i = 0; i < n; i++) {
        bool sorted = true;
        for (size_t j = 1; j < n - i; j++) {
            if (S[j] < S[j - 1]) {
                std::swap(S[j], S[j - 1]);
                sorted = false;
            }
        }
        if (sorted) return;
    }
}

int main() {
    std::vector<int> vec = { 5, 2, 1, 8, 7, 3 };
    bubbleSort(vec);
    for (auto& n : vec)
        std::cout << n << ", ";
    std::cout << std::endl;
    return 0;
}
