//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            ans^= nums[i];
        }
        
        int temp = ans;
        int bit = -1;
        int idx = 0;
        // cout<<temp;
        while(temp > 0){
            bit++;
            temp>>=1;
        }

        int first =0;
        for(int i =0;i<nums.size();i++){
            if((nums[i]>>bit & 1) == 1){
                // cout<<nums[i]<<" ";
                first^=nums[i];
            }
        }
        
        return {first^ans, first};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends