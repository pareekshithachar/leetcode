//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        
        if(N < M ) return -1;
        int sunday = S/7;
        int buydays = S - sunday;
        int totalfood = S*M;
        if(totalfood%N == 0){
            if((S*M)/N > buydays) return -1;
            return (S*M)/N;
        }else{
            if((S*M)/N  + 1 > buydays) return -1;
            return (S*M)/N + 1;
        }
     
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends