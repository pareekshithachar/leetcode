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
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0){
                zeros.push_back(i);
                continue;
            }
            res*=nums[i];
        }
        vector<long long int> ans(n,0);
        if(zeros.size() > 1) return ans;
        
        for(int i =0;i<nums.size();i++){
            if((zeros.size() == 1 && nums[i] == 0) || zeros.size()==0){
                ans[i] = res/(nums[i]==0?1:nums[i]);
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