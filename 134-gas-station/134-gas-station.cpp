class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int res = -1;
            vector<int> diff(gas.size());

            for(int i=0;i<gas.size();++i)
                diff[i]=gas[i]-cost[i];
            
            for(int i=diff.size()-2;i>=0;--i)
                diff[i]+=diff[i+1];
            
            if(diff[0] >= 0)
                res=max_element(diff.begin(), diff.end()) - diff.begin();
            
            return res;
        }
};