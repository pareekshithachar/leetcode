class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        string maxi ="";
        for(int i=0;i<n;i++){
            int left =i, right =i;
            while(left>=0 && right <n && s[left] == s[right]){
                left--;
                right++;
            }
            left++;
            right--;
            string temp = s.substr(left, right-left +1);
            if(maxi.length()<temp.length()) maxi = temp;
            
            left = i; 
            right = i+1;
            while(left>=0 && right <n && s[left] == s[right]){
                left--;
                right++;
            }
            left++;
            right--;
         temp = s.substr(left, right-left +1);
            if(maxi.length()<temp.length()) maxi = temp;
        }
        return maxi;
        
    }
};