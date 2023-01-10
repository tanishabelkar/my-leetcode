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
        vector<int> psum(arr.size() + 1);
        psum[0] = 0;
        for (int i = 0; i < arr.size(); ++i)
            psum[i + 1] = arr[i] + psum[i];
        
        unordered_map<int, int> last;
        int ans;
        for (int i = 0; i < psum.size(); ++i)
        {
            if (last.find(psum[i]) != last.end())
                ans = max(i - last[psum[i]], ans);
            else
                last[psum[i]] = i;
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