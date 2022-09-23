class Solution
{
    vector<vector < string>> res;

    bool safe(vector<string> board, int r, int c)
    {
       	// check row
        for (int i = 0; i < board.size(); ++i)
        {
            if (i != c && board[r][i] == 'Q')
                return false;
        }

       	// check column
        for (int i = 0; i < board[0].size(); ++i)
        {
            if (i != r && board[i][c] == 'Q')
                return false;
        }
        
        // check diagonals
        int i = r - 1, j = c - 1;
        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q')
                return false;
            --i, --j;
        }
        i = r + 1, j = c + 1;
        while (i < board.size() && j < board.size())
        {
            if (board[i][j] == 'Q')
                return false;
            ++i, ++j;
        }
        i = r - 1, j = c + 1;
        while (i >= 0 && j < board.size())
        {
            if (board[i][j] == 'Q')
                return false;
            --i, ++j;
        }
        i = r + 1, j = c - 1;
        while (j >= 0 && i < board.size())
        {
            if (board[i][j] == 'Q')
                return false;
            ++i, --j;
        }
        return true;
    }

    void backtrack(vector<string> board, int q, int n, int row)
    {
        if (q > n)
            return;
        else if (q == n)
        {
           	// for (auto b: board) cout << b << endl;
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (board[row][i] == '.' && safe(board, row, i))
            {
                board[row][i] = 'Q';
                backtrack(board, 1 + q, n, row + 1);
                board[row][i] = '.';
            }
        }
    }

    public:
        vector<vector < string>> solveNQueens(int n)
        {
            vector<string> b(n);
            string s(n,'.');
            for (int i = 0; i < n; ++i)
                b[i]=s;
            backtrack(b, 0, n, 0);
            return res;
        }
};