class Solution {
public:
    
    class Compare
    {
        public:
        bool operator() (const pair<char, int> &p1, const pair<char, int> &p2) const
        {
            return p1.second<p2.second;
        }
    };
    
    string frequencySort(string s) 
    {
        map<char, int> m;
        for(auto c:s)
            m[c]++;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for(auto it:m)
            pq.push(it);
        string res;
        while(!pq.empty())
        {
            for(int i=0;i<m[pq.top().first];++i)
                res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};