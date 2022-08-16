class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> nge;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && s.top() < nums2[i])
                s.pop();
            if (s.empty())
            {
                nge[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            else
            {
                nge[nums2[i]] = s.top();
                s.push(nums2[i]);
            }
        }
        
        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); ++i)
            res[i] = nge[nums1[i]];
        
        return res;
    }
};