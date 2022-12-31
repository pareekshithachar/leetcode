//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int countFlips(int a[],int n)
    {
        //code here.
        int on=0;
        for(int i =0;i<n;i++){
            if(a[i] == 1) on++;
        }
        int off = n-on;
        bool flag = 0;
        int count = 0;
        for(int i =0;i<n;i++){
            if((flag == 0 && a[i] == 1) || (flag == 1 && a[i] == 0)){
                continue;
            }

            count++;
            flag = !flag;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        cout<<ob.countFlips(a,n)<<endl;
    }
    return 0;
}


// } Driver Code Ends