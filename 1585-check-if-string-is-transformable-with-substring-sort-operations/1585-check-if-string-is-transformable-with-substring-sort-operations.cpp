class Solution {
public:
    vector<vector<int>> pLoc;
    vector<int> ptr;
    
    bool isPossible(string& s, int num){
        for(int i=0;i<num;i++){
            // if(ptr[i]==-1) continue;
            if(ptr[i]>=pLoc[i].size()) continue;
            if(pLoc[i][ptr[i]]<pLoc[num][ptr[num]]) return false;
        }
        return true;
    }
    bool isTransformable(string s, string t) {
        pLoc.resize(10);//has indices
        ptr.resize(10,-1); // has count
        
        for(int i=0;i<s.length();i++) {
            ptr[s[i]-'0']=0;
            pLoc[s[i]-'0'].push_back(i);
        }
        
        for(int i=0;i<t.length();i++){
            int num = t[i]-'0';
            if(ptr[num]==-1) return false;
            if(isPossible(s,num)) ptr[num]++;
            else return false;
        }
        return true;
    }
};