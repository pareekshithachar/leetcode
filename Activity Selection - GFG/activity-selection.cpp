//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return b.second > a.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>check;
        for(int i=0;i<n;i++){
            check.push_back({start[i],end[i]});
            
        }
        sort(check.begin(), check.end(), comp);
        int count =1;
        int e = check[0].second;
        for(int i=1;i<n;i++){
            if(check[i].first > e){
                e = check[i].second;
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends