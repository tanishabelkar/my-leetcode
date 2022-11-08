class Solution 
{
public:
    string smallestSubsequence(string s) 
    {
        stack<char> st;
        unordered_map<char, int> lastInd; //store the last index of each char
        for (int i = 0; i < s.size(); ++i) lastInd[s[i]] = i;
        
        unordered_map<char, bool> vis;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (vis[s[i]])
                continue;
            
            while(!st.empty() && st.top() > s[i] && lastInd[st.top()] > i)
            {
                vis[st.top()] = false;
                st.pop();
            }
            
            st.push(s[i]);
            vis[s[i]] = true;
        }
        
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};