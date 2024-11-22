#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    void findWords(TrieNode* node, string prefix, vector<string>& results) {
        if (!node) return;

        if (node->isEndOfWord)
            results.push_back(prefix);

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                char nextChar = 'a' + i;
                findWords(node->children[i], prefix + nextChar, results);
            }
        }
    }

public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    vector<string> autocomplete(const string& prefix) {
        TrieNode* node = root;
        vector<string> results;

        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index])
                return results; // Префикс не найден
            node = node->children[index];
        }

        findWords(node, prefix, results);
        return results;
    }
};

#endif 
