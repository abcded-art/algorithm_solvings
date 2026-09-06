#include <iostream>
#include <string>
#include <array>
#include <memory>
using namespace std;

class Trie {
private:
    struct Node {
        array<unique_ptr<Node>, 26> child{};
        bool isWord = false;
    };

    Node root;

    const Node* findNode(const string& text) const {
        const Node* cur = &root;
        for (char ch : text) {
            int index = ch - 'a'; // 소문자 영어만 저장한다고 가정한다.
            if (index < 0 || index >= 26 || !cur->child[index]) return nullptr;
            cur = cur->child[index].get();
        }
        return cur;
    }

public:
    void insert(const string& word) {
        Node* cur = &root;
        for (char ch : word) {
            int index = ch - 'a';
            if (index < 0 || index >= 26) return;
            if (!cur->child[index]) cur->child[index] = make_unique<Node>();
            cur = cur->child[index].get();
        }
        cur->isWord = true;
    }

    bool search(const string& word) const {
        const Node* node = findNode(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(const string& prefix) const {
        return findNode(prefix) != nullptr;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");

    cout << boolalpha;
    cout << trie.search("apple") << '\n';
    cout << trie.search("app") << '\n';
    cout << trie.startsWith("app") << '\n';
}
