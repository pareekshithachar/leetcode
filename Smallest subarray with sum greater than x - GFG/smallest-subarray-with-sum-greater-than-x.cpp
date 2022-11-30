//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int j =0;
        int ans =INT_MAX;
        int sum =0;
        for(int i =0;i<n;i++){
            sum+=arr[i];
            
            while(sum > x){
                ans = min(ans, i-j+1);
                sum-=arr[j];
                j++;
                
            }
            
        }
        return ans == INT_MAX?0:ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends