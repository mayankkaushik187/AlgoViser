//Leetcode 648
class TrieNode {
public:
    TrieNode *children[26];
    bool isEndOfWord; // Leaf and end of word
};

class Solution {
private:
    TrieNode *root = new TrieNode();
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string result = "";
        // Insert all roots into Trie
        for (string rootWord : dictionary) {
            insertTrie(rootWord);
        }
        // Search all root words in Trie
        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                word += sentence[i];
            } 
            else {
                string hasRootWord = getRootWordTrie(word);
                if (hasRootWord != "") {
                    result += hasRootWord + " ";
                } else {
                    result += word + " ";
                }
                word = "";
            }
        }
        string hasRootWord = getRootWordTrie(word);
        if (hasRootWord != "") {
            result += hasRootWord + " ";
        } else {
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
    
    void insertTrie(string &word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            int letterIndex = word[i] - 'a';
            if (cur->children[letterIndex] == NULL) {
                cur->children[letterIndex] = new TrieNode();
            }
            cur = cur->children[letterIndex];
        }
        cur->isEndOfWord = true;
    }
    
    string getRootWordTrie(string &word) {
        TrieNode *cur = root;
        string rootWord = "";
        for (int i = 0; i < word.size(); i++) {
            int letterIndex = word[i] - 'a';
            if (cur->children[letterIndex] == NULL) {
                return "";
            }
            rootWord += word[i];
            cur = cur->children[letterIndex];
            if (cur->isEndOfWord == true) {
                return rootWord;
            }
        }
        return "";
    }
};
