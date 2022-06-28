class Solution {
public:
    void solve(int n,int l,string &s){
        if(l == n){
            return ;
        }
            string temp="";
            
            int count=1;
            long i=0;
            while(i < s.length()-1){
                if(s[i] == s[i+1]){
                    count++;
                }else{
                    temp+= to_string(count);
                    temp+=s[i];
                    count=1;
                }
                i++;
            }
                temp+=to_string(count);
                temp+=s[i];
        
        s=temp;
        solve(n,l+1,s);
        return;
    }
    string countAndSay(int n) {
        string s="11";
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        solve(n,2,s);
        return s;
    }
};