class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int last = -1;
        int res =0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                last = max(last, mp[s[i]]);
            }
            mp[s[i]]=i;
            res = max(res,i-last);
        }
        return res;
    }
};