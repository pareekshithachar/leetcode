class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        unordered_map<char,int>mp;
        for(auto x : s){
            q.push(x);
            mp[x]++;
        }
        int i = 0;
        while(!q.empty()){
            if(mp[q.front()]>1){
                i++;
                q.pop();
            }else{
                return i;
            }
        }
        return -1;
    }
};