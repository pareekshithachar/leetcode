class Solution {
public:
bool isPalindrome(string s) {
string res = "";
for (int i = 0; i < s.length() ; i++){
char c = tolower(s[i]);

        if ((c >= 'a' && c <= 'z') || (c >= '0' && c<='9'))  {
            res+= c;
        }
    }
    
    if (res.length() <= 1) return true;
    
    int i = 0;
    int j = res.length()-1;
    
    while (i<j){
        if (res[i++] != res[j--]) return false;
    }
    
    return true;
}
};