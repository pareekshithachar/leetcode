class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int total=0;
        vector<int>diff;
        for(auto x : costs){
            total+= x[0];
            diff.push_back(x[1] - x[0]);
        }
        sort(diff.begin(),diff.end());
       
        
        for(int i=0;i<costs.size()/2;i++){
            
            total+= diff[i];
        }
        return total;
    }
};