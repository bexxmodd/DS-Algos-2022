#include <iostream>
#include <array>

class TrieNode {
public:
    std::array<TrieNode*, 26> successors{};
    bool word;
    char letter;

    TrieNode() : word(false), letter('\0') { }
};

class Trie {
public:
    TrieNode* root;

    void insert(const std::string& str) {
        TrieNode* curr = root;
        for (size_t i = 0; i < str.size(); i++) {
            if (!curr->successors[str.at(i) - 'a']) {
                curr->successors[str.at(i) - 'a'] = new TrieNode;
                curr->successors[str.at(i) - 'a']->letter = str.at(i);
            }
            curr = curr->successors[str.at(i) - 'a'];
        }
        curr->word = true;
    }

};
