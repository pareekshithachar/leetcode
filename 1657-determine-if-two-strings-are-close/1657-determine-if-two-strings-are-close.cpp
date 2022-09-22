class Solution {
public:

bool closeStrings(string word1, string word2) {
    vector<int> f(26,0),f1(26,0);
    map<char,int> m,m1;
    for(auto x: word1) m[x]++;
    for(auto x: word2) m1[x]++;
    
    for(auto x: m){
        if(m1.find(x.first)==m1.end()) return false;
    }
    for(auto x: m1){
        if(m.find(x.first)==m.end()) return false;
    }
    
    for(auto x: word1) f[x-'a']++;
    for(auto x: word2) f1[x-'a']++;
    
    sort(f.begin(),f.end());
    sort(f1.begin(),f1.end());
    
    for(int i=0; i<26; i++){
        if(f[i]!=f1[i]) return false;
    }
    
    return true;
    }
};

