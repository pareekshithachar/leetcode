class Solution {
public:
    int calc(int left, int right, int top, int bottom,vector<vector<int>>& grid){
        int sum =0;
        int c1 =(left+right)/2, c2 = (left+right)/2;
        bool flag = true;
        for(int i = top;i<=bottom;i++){
            if(c1==c2){
                sum+= grid[i][c1];
            }else{
                sum+=(grid[i][c1] + grid[i][c2]);
            }
            if(c1 == left){
                flag  = false;
            }
            if(!flag){
                c1+=1;
                c2-=1;
            }else{
                c1-=1;
                c2+=1;
            }
        }
        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>ans;
        int m = grid.size();
        int n = grid[0].size();
       
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                int l = j,r = j;
                int b=i;
                while( l >=0 && r<n && b<m){
                    int sum = calc(l,r,i,b,grid);
                    l--;
                    r++;
                    b=b+2;
                    bool na = true;
                    if(ans.size() <3){
                        if(!ans.count(sum)){
                            ans.insert(sum);
                        }
                        // cout<<sum<<" ";
                    }else{
                        if(!ans.count(sum)){
                            if(sum > *ans.begin()){
                              ans.erase(ans.begin());
                              ans.insert(sum);  
                            }
                            
                   
                        }
                    }
                }
                
            }
        }
        vector<int>a;
        for(auto x : ans){
            a.push_back(x);
        }
        reverse(a.begin(),a.end());
        return a;
    }
};