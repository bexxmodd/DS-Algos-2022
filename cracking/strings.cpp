#include <iostream>
#include <array>

bool palindromePermutation(const std::string& str) {
    std::array<int, 26> alpha{};
    for (char c : str) {
        if (c != ' ')
            alpha[c - 'a']++;
    }

    int count = 0;
    for (size_t i = 0; i < alpha.size(); i++) {
        if (alpha[i] % 2 != 0)
            ++count;
        if (count > 1)
            return false;
    }
    return true;
}

bool oneAway(const std::string& s1, const std::string& s2) {
    std::array<int, 26> alpha{};
    for (char c : s1)
        alpha[c - 'a']++;

    for (char c : s2)
        alpha[c - 'a']--;

    int res = 0;
    for (size_t i = 0; i < alpha.size(); i++) {
        res += alpha[i];
    }
    return abs(res) < 2;
}

int main() {
    std::cout << palindromePermutation("tact coa") << std::endl;
    std::cout << palindromePermutation("abbbbac") << std::endl;
    std::cout << palindromePermutation("askjdhaskdjh") << std::endl;
    std::cout << palindromePermutation("aaabbbccdd") << std::endl;
    std::cout << oneAway("pale", "pal") << std::endl;
    std::cout << oneAway("pales", "pal") << std::endl;
    std::cout << oneAway("pales", "bales") << std::endl;
    std::cout << oneAway("pales", "pale") << std::endl;
    return 0;
}
