class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {
            vector<bool> visc(matrix[0].size(), false), visr(matrix.size(), false);
            for (int i = 0; i < matrix.size(); ++i)
            {
                for (int j = 0; j < matrix[i].size(); ++j)
                {
                    if (matrix[i][j] == 0)
                        visc[j] = visr[i] = true;
                }
            }

            for (int i = 0; i < visr.size(); ++i)
            {
                if (visr[i])
                {
                    for (int j = 0; j < matrix[0].size(); ++j)
                        matrix[i][j] = 0;
                }
            }

            for (int j = 0; j < visc.size(); ++j)
            {
                if (visc[j])
                {
                    for (int i = 0; i < matrix.size(); ++i)
                        matrix[i][j] = 0;
                }
            }
        }
};