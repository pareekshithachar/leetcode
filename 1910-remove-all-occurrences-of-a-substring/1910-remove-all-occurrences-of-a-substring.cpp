class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp = s.substr(0,part.length());
        for(int i= part.size(); i<s.size();i++){
            if(temp.size() != part.size()){
                temp+= s[i];
            }
            else if(temp == part){
                s.erase(s.begin() + i- part.length(), s.begin() + i);
                
                i=-1;
                temp ="";
                
            }else{
                
                temp.erase(temp.begin() + 0, temp.begin() + 1);
                temp+= s[i];
                
            }
        }
        if(temp == part){
            s.erase(s.end() - part.length(), s.end());
        }
        return s;
    }
};