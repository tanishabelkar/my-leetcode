//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int l = 0, r = 0, last = 0;
        while (k > 0 && l < n && r < m)
        {
            if (arr1[l] < arr2[r])
            {
                last = arr1[l];
                l++;
            }
            else
            {
                last = arr2[r];
                r++;
            }
            
            k--;
        }
        
        while (k > 0 && l < n)
        {
            last = arr1[l];
            l++;
            k--;
        }
        
        while (k > 0 && r < m)
        {
            last = arr2[r];
            r++;
            k--;
        }
        
        return last;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends