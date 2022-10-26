//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool comp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
        if(b.second == a.second){
            return a.first.second < b.first.second;
        }
        return b.second > a.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int,int>,int>>check;
        for(int i=0;i<N;i++){
            check.push_back({{S[i],i+1},F[i]});
            
        }
        sort(check.begin(), check.end(), comp);
        vector<int>ans;
        ans.push_back(check[0].first.second);
        int e = check[0].second;
        for(int i = 1;i < N;i++){
            if(check[i].first.first > e){
                e = check[i].second;
                ans.push_back(check[i].first.second);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends