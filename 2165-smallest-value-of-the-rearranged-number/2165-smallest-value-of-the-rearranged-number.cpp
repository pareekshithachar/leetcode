class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg = false;
        if(num <0){
            neg = true;
            num*=-1;
        }
        if(num == 0) return num;
        string ans = to_string(num);
        
        if(neg){
            sort(ans.rbegin(),ans.rend());
        }else{
            sort(ans.begin(),ans.end());
        }
        
        int i=0; 
        while(ans[i] == '0'){
            i++;
        }
        if(ans[0]=='0'){
            swap(ans[i],ans[0]);
        }
        
        long long res = stoll(ans);
        return !neg? res: -1*res;
    }
    
};