//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        vector<int>x;
        for(int i =0;i<s.size();i++) if(s[i] == '[') x.push_back(i);
        int count =0;
        int ans =0,idx=0;
        for(int i =0;i<s.size();i++){
            if(s[i] == '['){
                count++;
                idx++;
            }else{
                count--;
                if(count<0){
                    ans+= x[idx] - i;
                    swap(s[i], s[x[idx]]);
                    count = 1;
                    idx++;
                }
            }
        }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends