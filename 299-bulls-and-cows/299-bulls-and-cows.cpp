class Solution {
public:
    string getHint(string secret, string guess) {
        int cow=0,bull=0;
        unordered_map<char,int>key;
        for(auto x : secret){
            key[x]++;
        }
        for(int i=0;i<guess.size();i++){
            if(guess[i] == secret[i]){
                bull++;
                key[guess[i]]--;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(guess[i] != secret[i] && key[guess[i]] > 0){
                cow++;
                key[guess[i]]--;
            }
        }
        string ans="";
        ans+= to_string(bull) +"A"+ to_string(cow)+"B";
        
        return ans;
    }
};