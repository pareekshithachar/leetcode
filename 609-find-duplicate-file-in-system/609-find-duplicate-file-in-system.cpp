class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<paths.size();i++){
            string s="";
            int j =0;
            while(paths[i][j] != ' '){
                s+=paths[i][j];
                j++;
            }
            
            
            while( j!= paths[i].size()){
                string filename ="";
                cout<<paths[i][j];
                
                
                while(paths[i][j] != ')'){
                    if(paths[i][j] == '('){
                        break;
                    }
                    if(paths[i][j]!=' ') filename+=paths[i][j];
                    j++;
                }
                string text = "";
                j++;
                while(paths[i][j] != ')'){
                    
                    text+=paths[i][j];
                    j++;
                }
                mp[text].push_back(s+'/' +filename);
                
                
                j++;
            }
            
            
        }
        vector<vector<string>>ans;
        for(auto x : mp){
            if(x.second.size() > 1){
                vector<string>res;
                for(auto y : x.second){
                    
                    res.push_back(y);
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};