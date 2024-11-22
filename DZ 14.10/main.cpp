#include "Trie.h"
#include <iostream>
#include <algorithm>

int main() {
    Trie trie;
    vector<string> dictionary = { "cat", "car", "cart", "call", "dog", "door", "duck", "dove", "zebra" };
    for (const string& word : dictionary)
        trie.insert(word);

    cout << "Autocomplete program. Type a prefix to search, or 'exit' to quit.\n";

    while (true) {
        cout << "\nEnter a prefix: ";
        string prefix;
        cin >> prefix;

        if (prefix == "exit")
            break;

        transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);

        vector<string> suggestions = trie.autocomplete(prefix);

        if (suggestions.empty())
            cout << "No suggestions found for prefix: " << prefix << endl;
        else {
            cout << "Suggestions: ";
            for (const string& word : suggestions)
                cout << word << " ";
            cout << endl;
        }
    }

    cout << "Program terminated. Goodbye!\n";
    return 0;
}
