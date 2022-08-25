class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x = arr2[0];
        for(int i=1;i<arr2.size();i++){
            x ^= arr2[i];
        }
        int y = arr1[0];
        for(int i=1;i<arr1.size();i++){
            y ^= arr1[i];
        }
        return x&y;
    }
};