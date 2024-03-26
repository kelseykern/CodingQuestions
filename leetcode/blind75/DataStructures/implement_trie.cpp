class TrieNode
{
public:
    TrieNode *links[26];
    bool isLeaf = false;
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        for (char c : word)
        {
            // if this letter does not have a trie in our trie
            if (!temp->links[c - 'a'])
            {
                // add a new trie for it
                temp->links[c - 'a'] = new TrieNode();
            }
            // go to this trie's trienode so we can continue to the next letter
            temp = temp->links[c - 'a'];
        }
        // when the word is done being inserted, we mark it's end
        temp->isLeaf = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        for (char c : word)
        {
            // if this letter does not exist, the word does not exist
            if (!temp->links[c - 'a'])
                return false;
            // otherwise keep going down the trie to the next trienode
            temp = temp->links[c - 'a'];
        }
        // we may have found all letters, but if it was not marked as a word..
        return temp->isLeaf;
    }

    // same as search but does not check if isLeaf, only checks if prefix exists
    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (char c : prefix)
        {
            if (!temp->links[c - 'a'])
                return false;
            temp = temp->links[c - 'a'];
        }
        return true;
    }
};
