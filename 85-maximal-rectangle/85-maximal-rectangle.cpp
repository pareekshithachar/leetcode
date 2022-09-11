class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int n=matrix[0].size();
        int m=matrix.size();
        vector<int>height(n,0);
        int left[n];
        int right[n];
        int ans=0;
        stack<int>s;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(matrix[i][j]=='1'){
                    height[j]++;
                    
                }else{
                    height[j]=0;
                }   
            }
            
            for(int k=0;k<n;k++){
                
                    if(s.empty()){
                        s.push(k);
                        left[k]=0;
                    }else{
                        while(!s.empty() and height[s.top()]>=height[k]) s.pop();
                        if(s.empty()) left[k]=0;
                        else left[k]=s.top()+1;
                        s.push(k);                         
                    }
                
                }
                while(!s.empty()) s.pop();
                
                for(int k=n-1;k>=0;k--){
                    if(s.empty()){
                        s.push(k);
                        right[k]=n-1;
                    }else{
                        while(!s.empty() and height[s.top()]>=height[k]) s.pop();
                        if(s.empty()) right[k]=n-1;
                        else right[k]=s.top()-1;
                        s.push(k);                         
                    }
                }
            
                while(!s.empty()) s.pop();
                for(int k=0;k<n;k++){
                    ans=max(ans,height[k]*(right[k]-left[k]+1));
                }
            cout<<ans<<" ";
        }
        return ans;
    }
};