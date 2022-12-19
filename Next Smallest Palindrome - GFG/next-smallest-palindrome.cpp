//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool ispalin(vector<int>&num, int n){
        int i =0;
        int j = n-1;
        while(i<j){
            if(num[i] != num[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
    void addone(vector<int>&num, int n, int idx){
        int i = idx;
        int carry =1;
        while(i >=0 && carry == 1){
            int temp = num[i] + 1;
            carry = temp/10;
            temp = temp%10;
            num[i] = temp;
            i--;
        }
        if(carry == 1){
            num.insert(num.begin(), carry%10);
        }
        return ;
    }
    bool isgreater(vector<int>&nums, int mid, int n){
        int i = mid-1;
        int j = mid+1;
        if(n%2 == 0) j--;
        while( i >=0 && j < n){
            if(nums[i] != nums[j]){
                return nums[i] > nums[j];
            }
            i--;
            j++;
        }
        return true;
    }
    void transform(vector<int>&num, int n){
        int start = n/2-1;
        int end = start+1;
        if(n%2) end++;
        while(start >= 0 && end < n){
            num[end] = num[start];
            start--;
            end++;
        }
    }
    
	vector<int> generateNextPalindrome(int nums[], int n) {
	    // code here
	    vector<int>num(n);
	    for(int i =0;i<n;i++) num[i] = nums[i];
	    if(ispalin(num,n)){
	        addone(num,n,n-1);
	        
	        if(num.size() == 1){
	            return num;
	        }
	    }
	    n = num.size();
	    
	    if(n%2){
	        int mid = n/2;
	        if(isgreater(num,mid,n)){
	            transform(num,n);
	        }else{
	            addone(num,n,mid);
	            transform(num,n);
	        }
	    }else{
	        int mid = n/2;
	        if(isgreater(num,mid,n)){
	            transform(num,n);
	        }else{
	            addone(num,n,mid-1);
	            transform(num,n);
	        }
	    }
	    
	    return num;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends