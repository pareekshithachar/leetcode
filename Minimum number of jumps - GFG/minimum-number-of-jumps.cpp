//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int nums[], int n){
        // Your code here
        if(n == 1) return 0;
        if(nums[0] == 0) return -1;
         int farjump=0,end=0,count=0;
         for(int i=0;i<n-1;i++){
             farjump=max(farjump,i+nums[i]);
             if(i==end){
                 count++;
                 if(end == farjump) return -1;
                 end=farjump;
                 
             }
         }
         return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends