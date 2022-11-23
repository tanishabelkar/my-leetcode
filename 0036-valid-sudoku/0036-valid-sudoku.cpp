class Solution 
{
public:
    
    bool validblock(vector<vector<char>>& board, int sr, int sc)
    {
        unordered_map<char, int> m;
        for(int i=sr;i<sr+3;++i)
        {
            for(int j=sc;j<sc+3;++j)
            {
                if(isdigit(board[i][j]))
                {
                    m[board[i][j]]++;
                    if(m[board[i][j]]>1)
                        return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //check each row
        for(int i=0;i<9;++i)
        {
            unordered_map<char, int> m;
            for(int j=0;j<9;++j) 
            {
                if(isdigit(board[i][j]))
                {
                    m[board[i][j]]++;
                    if(m[board[i][j]]>1)
                        return false;
                }
            }
        }
        
        //check each column
        for(int i=0;i<9;++i)
        {
            unordered_map<char, int> m;
            for(int j=0;j<9;++j) 
            {
                if(isdigit(board[j][i]))
                {
                    m[board[j][i]]++;
                    if(m[board[j][i]]>1)
                        return false;
                }
            }
        }
        
        //check each grid
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                if(!validblock(board, i, j))
                    return false;
            }
        }
        
        return true;
    }
};