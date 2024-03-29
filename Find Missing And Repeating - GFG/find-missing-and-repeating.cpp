//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        for(int i =0;i<n;i++){
            int x = arr[i]%n - 1;
            if(x < 0) x =n-1;
            arr[x] += n;
        }
        int *ans;

        for(int i =0;i<n;i++){
            if((arr[i]-1)/n == 0){
                ans[1] = i+1;
            }
            if((arr[i]-1)/n >= 2){
                ans[0] = i+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends