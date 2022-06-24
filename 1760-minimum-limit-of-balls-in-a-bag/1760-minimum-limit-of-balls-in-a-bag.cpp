class Solution {
public:
    bool check(int x,vector<int> &v,int mx){
      int i;
        
      int curr=0;
        for (i=0; i<v.size(); i++){
            
            curr+=(v[i]/x);
            
            if (v[i]%x==0){
                curr--;
            }
        }
        
        if (curr<=mx){
            return true;
        }
        
     return false;
    }
    
    int minimumSize(vector<int>& v, int mx) {
        sort(v.begin(),v.end());
       
        int l=1;
        int r=v[v.size()-1];
        
        while (r-l>1){
            int mid=l+(r-l)/2;
            
            if (check(mid,v,mx)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if (check(l,v,mx)){
            return l;
        }
        else{
            return r;
        }
    }
};