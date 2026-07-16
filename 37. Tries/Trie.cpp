#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag;

    Node() {
        for(int i = 0; i < 26; i++)
            links[i] = NULL;
        flag = false;
    }

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{

    private:
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;  
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    cout << trie.search("apple") << endl;   // 1 (true)
    cout << trie.search("app") << endl;     // 1 (true)
    cout << trie.search("appl") << endl;    // 0 (false)
    cout << trie.search("bat") << endl;     // 1 (true)
    cout << trie.search("bad") << endl;     // 0 (false)

    cout << trie.startsWith("app") << endl; // 1 (true)
    cout << trie.startsWith("ba") << endl;  // 1 (true)
    cout << trie.startsWith("cat") << endl; // 0 (false)

    return 0;
}

