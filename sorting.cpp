#include <iostream>
#include <vector>

template<class T>
void insertionSort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        T cur = arr[i];
        size_t hole = i;
        while (hole > 0 && arr[hole - 1] > cur) {
            arr[hole] = arr[hole - 1];
            --hole;
        }
        arr[hole] = cur;
    }
}

int main() {
    std::vector<int> A = { 5,2,4,6,1,3 };
    insertionSort(A);
    for (size_t i = 0; i < A.size(); i++)
        std::cout << A[i] << ", ";
    std::cout << std::endl;
    return 0;
}
