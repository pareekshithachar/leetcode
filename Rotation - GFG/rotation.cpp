//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findpivot(int arr[], int n){
        int l = 0;
        int h = n-1;
        while(l<h){
            int mid = l+(h-l)/2;
            
            if(arr[mid] >= arr[0]){
                l = mid+1;
            }else{
                h = mid;
            }
        }
        return l;
    }
	int findKRotation(int arr[], int n) {
	    // code here
	    int ans = findpivot(arr, n);
	    if(ans == n - 1){
	        if(arr[0] < arr[n-1]){
	            return 0;
	        }
	        return n-1;
	    } 
	    return ans%n;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends