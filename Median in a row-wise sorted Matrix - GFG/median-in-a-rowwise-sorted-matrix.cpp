//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int small(vector<int>&num, int x){
        int l = 0, h = num.size()-1;
        while(l<h){
            int mid = l+(h-l)/2;
            if(num[mid] <= x){
                l= mid+1;
            }else{
                h= mid-1;
            }
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        
        int l = 1;
        int h = 2000;
        int idx = (R*C/2);
        
        while(l<=h){
            int mid = l+(h-l)/2;
            int count =0;
            
            for(int i =0;i<R;i++){
                count+= upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            
            if(count <= idx){
                l = mid+1;
            }else h= mid-1;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends