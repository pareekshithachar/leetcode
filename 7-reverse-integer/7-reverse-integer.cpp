class Solution {
public:
    int reverse(int x) {
        string s = "";
        int temp = x;
        while(temp){
            s+=(temp%10 + '0');
  
            temp/=10;
        }
        long ans = 0;
   
        int k = 0;
        for(int i = s.length() - 1; i >=0; --i){
            ans += (s[i] - '0')*pow(10, k++);
        }
        return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans ;

    }
};