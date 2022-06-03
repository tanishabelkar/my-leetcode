class NumMatrix
{
    public:

    vector<vector < int>> matrix;
    vector<vector < int>> rows;

    NumMatrix(vector<vector < int>> &mat)
    {
        matrix = rows = mat;
        for (int i = 0; i < rows.size(); ++i)
        {
            for (int j = 1; j < rows[i].size(); ++j)
                rows[i][j] += rows[i][j - 1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for (int i = row1; i <= row2; ++i)
        {
            if (col1 != 0)
                res += (rows[i][col2] - rows[i][col1 - 1]);
            else res += rows[i][col2];
        }
        return res;
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */