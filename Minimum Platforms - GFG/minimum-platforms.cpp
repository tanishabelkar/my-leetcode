//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int em = 0, pt = 1;
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int i = 1, j = 0;
    	bool prev = true;
    	
    	while (i < n && j < n)
    	{
    	   // cout << dep[j] << " " << arr[i] << "\n";
    	    if (arr[i] <= dep[j])
    	    {
    	        if (em > 0)
    	            em--;
    	        else pt++;
    	        i++;
    	    }
    	    else
    	    {
    	        if (em + 1 <= pt)
    	            em++;
    	        j++;
    	    }
    	}
    	
    	
    	return pt;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends