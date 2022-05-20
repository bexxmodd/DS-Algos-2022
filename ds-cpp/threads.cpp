#include <iostream>
#include <thread>
#include <mutex>

int val = 0;

void f(int n) {
    std::mutex m;
    std::lock_guard<std::mutex> lockGuard(m);
    for (int i = 0; i < n; i++)
        val += i;
}

void f2() {
    std::cout << "HERE" << std::endl;
}

int main() {
    std::thread t1(f, 5);
    std::thread t2(f, 2);
    std::thread t3(f, 7);

    t1.join();
    t2.join();
    t3.join();
    std::cout << val << std::endl;
    return 0;
}
