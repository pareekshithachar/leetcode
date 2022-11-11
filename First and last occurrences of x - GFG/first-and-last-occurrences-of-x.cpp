//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int low(int arr[], int n , int x){
    int l = 0;
    int h = n-1;
    int ans=-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        
        if(arr[mid] >= x){
            if(arr[mid] == x) ans = mid;
            h--;
        }else{
            l++;
        }
    }
    return ans;
}
int high(int arr[], int n , int x){
    int l = 0;
    int h = n-1;
    int ans=-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        
        if(arr[mid] <= x){
            if(arr[mid] == x) ans = mid;
            l++;
        }else{
            h--;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
   
    return {low(arr,n,x),high(arr,n,x)};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends