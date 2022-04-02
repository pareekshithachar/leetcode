class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int>left(heights.size(),0),right(heights.size(),0);
        for(int i =0 ;i<heights.size();i++){
            if(s.empty()){
            left[i] =0 ;
            s.push(i);
            }else{
                while(!s.empty() && heights[s.top()] >= heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    left[i] = 0;
                }else{
                    left[i] = s.top() + 1;
                }
                s.push(i);
            }
        }
        while(!s.empty() ) s.pop();
        int n = heights.size();
        for(int i = n-1; i>=0;i--){
            if(s.empty()){
                right[i] = n-1;
                s.push(i);
            }else{
                while(!s.empty() && heights[s.top()] >= heights[i]){
                  s.pop();  
                }
                if(s.empty()) right[i] = n-1;
                else{
                    right[i] = s.top() - 1;
                }
                s.push(i);
            }
        }
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            ans = max(ans, heights[i]*(right[i]-left[i]+1));
        }
     return ans;   
    }
};