class Solution {
public:
    int candy(vector<int>& A) {
         int n=A.size();
    assert(n>=1);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
            dp[i]=dp[i-1]+1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1] && dp[i]<=dp[i+1]+1)
        {
            dp[i]=dp[i+1] + 1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=dp[i];
    return ans;
    }
};
// 4 3 2 1 