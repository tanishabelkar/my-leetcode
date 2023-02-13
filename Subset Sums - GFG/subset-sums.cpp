//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    vector<int> res;
    vector<bool> vis;
    void ss(vector<int> arr, int curr, int ind, int n)
    {
        if (n == 0)
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = ind; i < arr.size(); ++i)
        {
            if (!vis[i])
            {
                vis[i] = true;
                curr += arr[i];
                ss(arr, curr, i, n - 1);
                curr -= arr[i];
                vis[i] = false;
            }
        }
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // vector<int> res;
        vis.resize(N, false);
        
        for (int i = 0; i <= N; ++i)
            ss(arr, 0, 0, i);
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends