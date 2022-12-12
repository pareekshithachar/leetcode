//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int windsize = 0;
        for(int i =0;i<n;i++){
            if(arr[i] <= k) windsize++;
        }
        int ans =0;
        int local = 0;
        if(windsize == 0) return 0;
        for(int i =0;i<windsize;i++){
            if(arr[i] > k){
                local++;
            } 
        }
        ans = local;

        for(int i = 0,j=windsize;j<n;j++,i++){
            if(arr[i] > k ) local--;
            if(arr[j] > k) local++;
            
            ans = min(ans,local);
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends