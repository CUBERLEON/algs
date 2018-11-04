class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    ~Trie()
    {
        delete root;
    }

    void insert(const string& word)
    {
        Node* cur = root;
        for (char c : word)
        {
            if (!cur->child[c - 'a']) cur->child[c - 'a'] = new Node();
            cur = cur->child[c - 'a'];
        }
        cur->word_end = true;
    }

    bool search(const string& word)
    {
        return search_aux(word, true);
    }

    bool search_prefix(const string& prefix)
    {
        return search_aux(prefix, false);
    }

private:
    struct Node
    {
        Node() : word_end(false)
        {
            for (int i = 0; i < 26; ++i) child[i] = nullptr;
        }

        ~Node()
        {
            for (int i = 0; i < 26; ++i) delete child[i];
        }

        Node* child[26];
        bool word_end;
    };

    Node* root;

    bool search_aux(const string& text, bool match_word)
    {
        Node* cur = root;
        for (char c : text)
        {
            if (!cur->child[c - 'a']) return false;
            cur = cur->child[c - 'a'];
        }
        return !match_word || cur->word_end;
    }
};