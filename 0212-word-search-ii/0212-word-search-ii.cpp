class TrieNode
{
    public:
        vector<TrieNode*> children;
    bool isTerminal = false;
    TrieNode(): children(26, NULL) {}
};
class Trie
{
    public:
        TrieNode * root;
    public:
        Trie()
        {
            this->root = new TrieNode();
        }
    void insertWord(string & word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!temp->children[idx])
            {
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->isTerminal = true;
    }
};
class Solution
{
    private:
        vector<string> ans;
    void solve(int row, int col, vector<vector < char>> &board, TrieNode *root, string &word)
    {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '-') return;
        char ch = board[row][col];
        if (root->children[ch - 'a'])
        {
            root = root->children[ch - 'a'];
            word.push_back(ch);
            if (root->isTerminal)
            {
                ans.push_back(word);
                root->isTerminal = false;
            }
            board[row][col] = '-';
            solve(row + 1, col, board, root, word);
            solve(row - 1, col, board, root, word);
            solve(row, col + 1, board, root, word);
            solve(row, col - 1, board, root, word);
            word.pop_back();
            board[row][col] = ch;
        }
    }
    public:
        vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
        {
            int m = board.size();
            int n = board[0].size();
            Trie *trie = new Trie();
            TrieNode *trieNode = trie->root;
            for (int i = 0; i < words.size(); i++)
            {
                trie->insertWord(words[i]);
            }
            string word = "";
            for (int row = 0; row < m; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    solve(row, col, board, trieNode, word);
                }
            }
            return ans;
        }
};