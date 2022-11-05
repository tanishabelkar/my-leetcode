class Solution
{
    public:
        vector<int> findRightInterval(vector<vector < int>> &intervals)
        {
            map<int, int> m;
            vector<int> res;
            for (int i = 0; i < intervals.size(); ++i) m[intervals[i][0]] = i;
            for (auto in: intervals)
            {
                if (m.lower_bound(in[1]) == m.end()) 
                    res.push_back(-1);
                else 
                    res.push_back(m.lower_bound(in[1])->second);
            }
            return res;
        }
};