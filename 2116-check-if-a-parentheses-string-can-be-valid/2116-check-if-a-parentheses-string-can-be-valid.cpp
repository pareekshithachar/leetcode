class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2 == 1) return false;
        int count =0;
        for(int i=0;i<s.size();i++){
            if(locked[i]== '1'){
                if(s[i] == ')'){
                    count--;
                }
                if(count <0) return false;
                if(s[i] == '('){
                    count++;
                }
            }else{
                count ++;
            }
        }
        count =0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i] =='1' ){
                if(s[i] == '('){
                    count --;
                }
                if(count < 0) return false;
                if(s[i] == ')'){
                    count++;
                }
            }else{
                count++;
            }
        }
        return true;
    }
};