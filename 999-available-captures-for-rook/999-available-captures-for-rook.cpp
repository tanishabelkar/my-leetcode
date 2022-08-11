class Solution
{
    public:
        int numRookCaptures(vector<vector < char>> &board)
        {
            int ans = 0;
            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board[i].size(); ++j)
                {
                    if (board[i][j] == 'R')
                    {
                       	// left
                        for (int k = j - 1; k >= 0; --k)
                        {
                            if (board[i][k] == 'B')
                                break;
                            else if (board[i][k] == 'p')
                            {
                                ans += 1;
                                break;
                            }
                        }
                       	// right
                        for (int k = j + 1; k < board[i].size(); ++k)
                        {
                            if (board[i][k] == 'B')
                                break;
                            else if (board[i][k] == 'p')
                            {
                                ans += 1;
                                break;
                            }
                        }
                       	// up
                        for (int k = i - 1; k >= 0; --k)
                        {
                            if (board[k][j] == 'B')
                                break;
                            else if (board[k][j] == 'p')
                            {
                                ans += 1;
                                break;
                            }
                        }
                       	// down
                        for (int k = i + 1; k < board.size(); ++k)
                        {
                            if (board[k][j] == 'B')
                                break;
                            else if (board[k][j] == 'p')
                            {
                                ans += 1;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            return ans;
        }
};