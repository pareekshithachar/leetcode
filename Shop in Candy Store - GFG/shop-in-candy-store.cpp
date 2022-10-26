//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        vector<int>c;
        for(int i = 0;i<N;i++){
            c.push_back(candies[i]);
        }
        sort(c.begin(),c.end());
        
        int mini =c[0];
        int maxi = c[N-1];
        int start = 1;
        int end = N - k;
        while(start < end){
            mini += c[start];
            end -= k;
            start++;
        }
        start = N-2;
        end  = k-1;
        while(end < start){
            maxi += c[start];
            end += k;
            start--;
        }
        return {mini,maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends