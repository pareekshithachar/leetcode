//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int nums[], int i, int d){
        int count = 1;
        int prev = nums[i];
        i--;
        while(i >= 0){
            if(prev - nums[i] == d){
                count++;
                prev = nums[i];
            }
            i--;
        }
        return count;
    }
    int lengthOfLongestAP(int A[], int n) {
        // code here
        int count = 1;
        for(int i =0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int d = A[j] - A[i];
                count = max(count, 1 + solve(A,i,d));
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends