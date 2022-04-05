class Solution {
public:
    vector<string> res;
    
    void generate(int n, string s,int open, int close){
        if(s.length() == 2*n){
            res.push_back(s);
            return;
        }
            if(open < n){
                // s+="(";
                
                generate(n, s + '(', open + 1, close);
            }
            if(close < open){
                // s+=")";
                generate(n,s + ')',open, close + 1);
            }
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        generate(n, s, 0,0);
        
        return res;
    }
};