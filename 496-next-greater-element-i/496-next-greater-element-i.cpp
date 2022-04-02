class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,stack<int>>mp;
        stack<int>st;
        vector<int>res;
        for(int i =nums2.size()-2;i>=0;i--){
            st.push(nums2[i+1]);
            mp[nums2[i]] = st;
        }
        for(int i = 0 ;i<nums1.size();i++){
            if(mp[nums1[i]].empty()){
                res.push_back(-1);
                continue;
            }  
            while(!mp[nums1[i]].empty()){
                
                if(mp[nums1[i]].top() > nums1[i]){
                    res.push_back(mp[nums1[i]].top());
                    break;
                }else{
                    mp[nums1[i]].pop();
                }
            }
            if(!mp[nums1[i]].empty()){
                continue;
            }else{
                res.push_back(-1);
            }
            
        }
       return res;
    }
};