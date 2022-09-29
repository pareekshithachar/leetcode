class Solution {
public:
   
    void solve(string digits,int index, string res, vector<string>dic, vector<string>&ans){
       if(index>= digits.length()){
           ans.push_back(res);
           return;
       }
        int value = digits[index] -'0';
        for(int i=0;i<dic[value].length();i++){
            res+=dic[value][i];
            solve(digits,index+1,res,dic,ans);
            res.pop_back();
        }
    return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>dic(10);
        if(digits.size() == 0) return {};
        dic= {"","", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        solve(digits, 0,"", dic, ans);
        return ans;
        
    }
};