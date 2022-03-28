// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char,pair<int,int>>mp;
//         int maxlen=0;
//         int curlen=0;
//         if(s.length() == 0) return 0;
//         for(int i=0; i<s.length();i++){
//             //p 
//             if(mp[s[i]].first == 0){
//                 curlen++;
//                 mp[s[i]].first++;
//                 mp[s[i]].second =i;
                
//             }
//             else{
//                 curlen =curlen - mp[s[i]].second;
//                 // mp.clear();
//                 mp[s[i]].second =i;
                
//             }
//             cout<<"curlen "<<curlen<<" ";
//             maxlen = max(curlen,maxlen);
//             cout<<"maxlen "<< maxlen<<" "<<"s[i] "<< s[i]<<endl;
            

            

//         }
//         return maxlen;
        
//     }
// };
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