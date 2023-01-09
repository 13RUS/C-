#include <iostream>

class Trie {
public:
    class TrieTree {
    public:
        TrieTree *child[26];
        bool isEndOfWord = false;
    };

    TrieTree *root;
    // ---------------------------------------
    Trie (){
        root = new TrieTree();
    }

    // ---------------------------------------
    void insert (std::string word) {
        TrieTree* current = root;

        for (auto &ch : word) {
            if (!current->child[ch-'a'])
                current->child[ch-'a'] = new TrieTree();

            current = current->child[ch-'a'];
        }
        current->isEndOfWord = true;
    }

    // ---------------------------------------
    bool search (std::string word){
        TrieTree* cur = root;

        for (auto &ch : word) {
            if (!cur->child[ch-'a']) return false;
            cur = cur->child[ch-'a'];
        }
        return cur->isEndOfWord ? true : false;
    }

    // ---------------------------------------
    bool startsWith (std::string prefix){
        TrieTree* cur = root;

        for (auto &ch : prefix) {
            if (!cur->child[ch-'a']) return false;
            cur = cur->child[ch-'a'];
        }
        return true;
    }
};

// ---------------------------------------
int main() {

    std::cout << "\n// ------- Testing Prefix Tree --------\n";
    Trie* obj = new Trie();


    // Input keys (use only 'a' through 'z' and lower case)
    std::string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };

    int n = sizeof(keys)/sizeof(keys[0]);

    // Construct trie
    for (int i = 0; i < n; i++)
        obj->insert(keys[i]);

    // Search for different keys
    char output[][32] = {"Not present in trie", "Present in trie"};

    // Search for different keys
    std::cout << "the" << " --- " << output[obj->search("the")] << std::endl;
    std::cout << "these" << " --- " << output[obj->search ("these")] << std::endl;
    std::cout << "their" << " --- " << output[obj->search ("their")] << std::endl;
    std::cout << "thaw" << " --- " << output[obj->search ("thaw")] << std::endl;

    return 0;
}
