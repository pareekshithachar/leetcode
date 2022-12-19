//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long res = 1;
        vector<int>zeros;
        vector<long long int> ans(n,0);
        vector<long long >left(n,1);
        vector<long long> right(n,1);
        for(int i =1;i<nums.size();i++){
            if(nums[i-1] == 0){
                zeros.push_back(i-1);
                continue;
            }
            res*=nums[i-1];
            left[i] = res;
            
        }
        if(nums[n-1]==0) zeros.push_back(n-1);
        res = 1;
        if(zeros.size() > 1) return ans;
        
        if(n == 2 && zeros.size() == 1){
            
            return {nums[1],nums[0]};
            
            
        }
        for(int i =n-2;i>=0;i--){
            if(nums[i+1] == 0){
                continue;
            }
            res*=nums[i+1];
            right[i] = res;
        }
        
        
        
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0 || zeros.size() == 0){
                ans[i] = left[i]*right[i];
            }

            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends