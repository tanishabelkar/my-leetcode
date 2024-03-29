class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &temp)
        {
            stack<pair<int, int>> st;
            vector<int> res(temp.size());
            for (int i = temp.size() - 1; i >= 0; --i)
            {
                while (!st.empty() && st.top().first <= temp[i])
                    st.pop();
                
                if (st.empty())
                    res[i] = 0;
                else
                    res[i] = st.top().second - i;
                
                st.push(make_pair(temp[i], i));
            }
            
            return res;
        }
};