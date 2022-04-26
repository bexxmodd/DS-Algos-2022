#include <iostream>
#include <vector>

using Partitions = std::vector<std::vector<std::string>>;

bool isPalindrome(std::string& s, size_t left, size_t right) {
    if (s.size() < 2)
        return true;
    while (left < right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

void dfs(
        Partitions& results, std::string& str,
        size_t start, std::vector<std::string>& currentList
    )
{
    if (start >= str.size())
        results.push_back(currentList);
    
    for (size_t end = start; end < str.size(); end++) {
        // if (isPalindrome(str, start, end)) {
            // add current substr in the currentList
            currentList.push_back(str.substr(start, end - start + 1));
            dfs(results, str, end + 1, currentList);
            
            // backtrack and remove the current substring from currentList
            currentList.pop_back();
        // }
    }
}

Partitions dfs(std::string s) {
    Partitions result{};
    std::vector<std::string> current;
    dfs(result, s, 0, current);
    return result;
}

int main() {
    std::string s1 = "anna";
    for (auto& v : dfs(s1)) {
        for (auto& s : v)
            std::cout << s << ", ";
        std::cout << std::endl;
    }
    return 0;
}
