class Solution {
public:
    string bin(int n){
        string s;
        
        while(n>0){
            if(n%2 == 0){
                s+='0';
            }else{
                s+='1';
            }
            n=n>>1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            auto x = s.find(bin(i));
            cout<<x<<" ";
            if(x == string::npos) return false;
        }
        return true;
    }
    
};