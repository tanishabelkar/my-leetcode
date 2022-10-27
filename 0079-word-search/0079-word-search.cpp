class Solution
{
    bool backtrack(vector<vector < char>> &board, string w, int ind, int i, int j)
    {
        if (ind >= w.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (w[ind] != board[i][j])
            return false;

        board[i][j] = '*';
        bool ans = backtrack(board, w, ind + 1, i + 1, j) ||
            backtrack(board, w, ind + 1, i - 1, j) ||
            backtrack(board, w, ind + 1, i, j + 1) ||
            backtrack(board, w, ind + 1, i, j - 1);
        board[i][j] = w[ind];

        return ans;
    }
    public:
        bool exist(vector<vector < char>> &board, string word)
        {
            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board[0].size(); ++j)
                {
                    if (backtrack(board, word, 0, i, j))
                        return true;
                }
            }
            return false;
        }
};

/*
A B C E
S F E S
A D E E
*/