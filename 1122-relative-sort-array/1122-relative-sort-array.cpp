class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>res;
       for(int i=0;i<arr1.size();i++){
           mp[arr1[i]]++;
       }
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]){
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(int i =0;i<mp.size();i++){
            while(mp[i]){
                res.push_back(i);
                mp[i]--;
            }
        }
        return res;
        
    }
};