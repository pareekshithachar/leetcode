//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> A){
        // code here
        int i,j;
    int n = A.size();
    for(i = n - 2;i >= 0;i --)
    {
        if(A[i] < A[i + 1])
            break;
    }
    if(i == -1)
    {
        reverse(A.begin(),A.end());
        return A;
    }
    
    for(j = n - 1;j > i;j --)
    {
        if(A[j] > A[i])
            break;
    }
    swap(A[j],A[i]);
    reverse(A.begin() + i + 1,A.end());
    return A;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends