//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int>mp;
        set<int>st;
        
        for(int i =0;i<k;i++){
            mp[A[i]]++;
            st.insert(A[i]);
        }
        vector<int>ans;
        ans.push_back(st.size());
        
        
        for(int i =k, j=0;i<n;i++,j++){
            mp[A[j]]--;
            if(mp[A[j]] == 0){
                st.erase(A[j]);
            }
            mp[A[i]]++;
            st.insert(A[i]);
            ans.push_back(st.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends