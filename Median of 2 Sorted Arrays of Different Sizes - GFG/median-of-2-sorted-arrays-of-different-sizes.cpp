//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        double ans =0;
        int tot = array1.size() + array2.size();
        int i =0, j=0;
        int count =-1;
        
        int flag =0;
        while(i<array1.size() && j < array2.size()){
            
            if(array1[i] < array2[j]){
                count++;
                if(count  ==  (tot - 1)/2){
                    flag =1;
                    ans = array1[i];
                    if(tot%2) return ans;
                    i++;
                    break;
                }
                i++;
            }else{
                count++;
                if(count  ==  (tot - 1)/2){
                    flag =1;
                    ans = array2[j];
                    if(tot%2) return ans;
                    j++;
                    break;
                }
                j++;
                
            }
            
            
        }
        if(!flag){
            while(i<array1.size()){
                
                count++;
                if(count  ==  (tot - 1)/2){
                    
                    ans = array1[i];
                    if(tot%2) return ans;
                    i++;
                    break;
                }
                i++;
                
            }
            while(j<array2.size()){
                count++;
                if(count  ==  (tot - 1)/2){
                    flag =1;
                    ans = array2[j];
                    if(tot%2) return ans;
                    j++;
                    break;
                }
                j++;
                
            }
        }
        double l = INT_MAX;
        if(i < array1.size()) l = array1[i];
        double r = INT_MAX;
        if(j < array2.size()) r = array2[j];
        ans = (ans + min(l,r))/2;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends