//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        queue<vector<string>>q;
        wordList.push_back(beginWord);
        set<string>st;
        st.insert(wordList.begin(),wordList.end());


        q.push({beginWord});
        st.erase(beginWord);
        while(!q.empty()){
            int size = q.size();
            vector<string>check;
            while(size--){

                vector<string>front = q.front();
                string cur = front.back();
                q.pop();
                if(ans.size() != 0 && ans[0].size() < front.size()) continue;
                if(cur == endWord){
                    if(ans.size() == 0){
                        ans.push_back(front);
                    }else{
                        if(ans.back().size() == front.size()){
                            ans.push_back(front);
                        }
                    }
                    
                    continue;
                }
                for(int i =0;i<cur.size();i++){
                    char orig = cur[i];
                    for(char ch = 'a'; ch<='z';ch++){
                        cur[i] = ch;
                        if(st.count(cur)){
                            check.push_back(cur);
                            front.push_back(cur);
                            q.push(front);
                            front.pop_back();
                        }
                    }
                    cur[i] = orig;
                }

            }
            for(int i =0;i<check.size();i++){

                st.erase(check[i]);
            }    

        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends