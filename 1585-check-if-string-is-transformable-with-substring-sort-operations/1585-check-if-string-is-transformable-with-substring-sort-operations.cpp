class Solution {
public:
    vector<int>count;
    vector<vector<int>>indx;
    bool ispos(string &s, int num){
        for(int i=0;i < num;i++){
            if(count[i] >= indx[i].size()) continue;
            if(indx[i][count[i]] < indx[num][count[num]]) return false;
        }
        return true;
    }
    bool isTransformable(string s, string t) {
        count.resize(10,-1);
        indx.resize(10);
        
        for(int i=0;i<s.size();i++){
            count[s[i] - '0'] = 0;
            indx[s[i] - '0'].push_back(i);
        }
        
        for(int i=0;i<t.size();i++){
            int num = t[i] - '0';
            if(count[num] == -1) return false;
            if(ispos(s,num)) count[num]++;
            else return false;
        }
        return true;
    }
};