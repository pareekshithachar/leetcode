//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    void solve(string &s, int start, int end, int count,string k, vector<string>&ans){
        if(end >= s.size()) return ;
        if(count == 0){
            
            string check = s.substr(start,s.size() - start +1);
            if(check.size() > 1 && check[0] == '0') return ;
            int temp = stoi(check);

            if(temp <= 255 && temp >=0){
                k+='.';
                k+= check;
                ans.push_back(k);
                return;
            }
        }
        string a =s.substr(start, end-start+1);
        if(stoi(a) <= 255){
            
            if(k != "") k+='.';
            solve(s,end+1,end+1,count-1,k+a,ans);
            if(k != "") k.pop_back();
            
            if(a[0] != '0') solve(s,start,end+1,count,k,ans);
        }
    }
    vector<string> genIp(string &s) {
        // Your code here
        vector<string>ans;
        if(s.size() > 12) return ans;
        string k ="";
        solve(s,0,0,3,k,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends