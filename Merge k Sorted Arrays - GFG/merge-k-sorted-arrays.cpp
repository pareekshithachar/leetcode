//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int>merge(vector<int>a, vector<int>b){
        int n = a.size(), m = b.size();
        vector<int>x;
        int i=0,j=0;
        while(i<n && j < m){
            if(a[i] < b[j]){
                x.push_back(a[i++]);
            }else{
                x.push_back(b[j++]);
            }
        }
        while(i<n){
            x.push_back(a[i++]);
        }
        while(j<m){
            x.push_back(b[j++]);
        }
        return x;
    }
    vector<int> mergesort(vector<vector<int>> arr, int start, int end){
        if(start == end){
            return arr[start];
        }
        if(end - start == 1) return merge(arr[start],arr[end]);
        int mid = start+(end-start)/2;
        vector<int>temp = mergesort(arr,start,mid);
        vector<int>temp1 = mergesort(arr,mid+1,end);
        
        return merge(temp,temp1);
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans;
        return mergesort(arr,0,K-1);
        
       
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends