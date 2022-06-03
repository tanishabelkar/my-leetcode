template < typename Map>
    bool map_compare(Map
        const &lhs, Map
        const &rhs)
    {
       	// No predicate needed because there is operator== for pairs already.
        return lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(),
                rhs.begin());
    }
class Solution
{
    public:

        vector<int> findSubstring(string s, vector<string> &words)
        {
            map<string, int> mw;
            for (auto w: words) mw[w]++;

            int n = words[0].size();
            vector<int> res;
            int i = 0;
            while (i < s.size())
            {
                if(mw.find(s.substr(i,n))==mw.end())
                {
                    ++i;
                    continue;
                }
                
                map<string, int> m;
                for (int j = i; j < min(s.size(), i + n *words.size()); j += n)
                {
                    string curr = s.substr(j, n);
                    m[curr]++;
                    
                }
               	//for(auto i:m)
               	  //cout<<i.first<<" "<<i.second;
               	//cout<<"\n";
                if (map_compare(m, mw)) res.push_back(i);
                ++i;
            }
            return res;
        }
};