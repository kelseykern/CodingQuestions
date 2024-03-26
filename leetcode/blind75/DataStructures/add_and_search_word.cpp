class WordDictionary
{
public:
    unordered_set<string> dict;
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        dict.insert(word);
    }

    bool search(string word)
    {
        // check each word in our dictionary
        for (auto dict_word : dict)
        {
            // if the words are different sizes, don't check those
            if (dict_word.size() == word.size())
            {
                int size = dict_word.size();
                // check each character
                for (int i = 0; i < size; i++)
                {
                    if (dict_word[i] == word[i] ||
                        word[i] == '.')
                    {
                        // if we checked every character and they all match
                        if (i == size - 1)
                            return true;
                    }
                    else
                        break;
                }
            }
        }
        return false;
    }
};

/*********************************************/

struct TrieNode
{
    bool isCompleteWord;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
};

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void addWord(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!curr->children[index])
            {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isCompleteWord = true;
    }

    // Search for a word in the Trie
    bool pathSearch(string word, TrieNode *root, int index)
    {
        if (index == word.size())
            return root->isCompleteWord;
        TrieNode *node = root;
        char c = word[index];
        int idx = c - 'a';
        if (c == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i])
                {
                    bool search = pathSearch(word, node->children[i], index + 1);
                    if (search)
                        return true;
                }
            }
            return false;
        }
        else
        {
            if (!node->children[idx])
                return false;
            return pathSearch(word, node->children[idx], index + 1);
        }
    }

    bool search(string word)
    {
        return pathSearch(word, root, 0);
    }
};
