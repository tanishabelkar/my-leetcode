//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int psum[n], ans = 0;
        psum[0] = arr[0];
        for (int i = 1; i < n; ++i)
            psum[i] = psum[i - 1] + arr[i];
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            if (mp.find(psum[i]) == mp.end())
            {
                mp[psum[i]] = i;
            }
            else 
            {
                ans = max(ans, i - mp[psum[i]]);
            }
            if (psum[i] == 0)
                ans = max(ans, i + 1);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends