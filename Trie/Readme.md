# C++ program to demonstrate auto-complete feature  using Trie data structure Functions
## TrieNode structure:

struct TrieNode represents a node in the Trie. It contains an array of pointers to child nodes (children) and a boolean flag (isWordEnd) indicating whether the node marks the end of a word.
## getNode function:

struct TrieNode *getNode() creates and initializes a new TrieNode with NULL children and isWordEnd set to false.
## insert function:

void insert(struct TrieNode *root, const string key) inserts a word into the Trie. It iterates through each character of the input word, creating new nodes as needed.
## search function:

bool search(struct TrieNode *root, const string key) checks whether a given word is present in the Trie.
## isLastNode function:

bool isLastNode(struct TrieNode* root) checks if a given node is the last node in the Trie (i.e., has no children).
## suggestionsRec function:

void suggestionsRec(struct TrieNode* root, string currPrefix) recursively prints all words in the Trie that have the given prefix.
## printAutoSuggestions function:

int printAutoSuggestions(TrieNode* root, const string query) finds and prints autocomplete suggestions for a given prefix. It returns 0 if no suggestions are found, -1 if the prefix is a complete word, and 1 if there are suggestions.
## main function:

The main function creates a Trie, inserts some sample words, and then prompts the user to enter a word for which autocomplete suggestions will be displayed.
The user is asked to enter a word, and the printAutoSuggestions function is called to display autocomplete suggestions based on the entered prefix.
