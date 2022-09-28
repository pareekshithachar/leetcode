class Solution {
public:
    void merge(vector<int>&a,int s, int e){
        int mid = (s+e)/2;
        vector<int>low(mid-s+1);
        vector<int>high(e-mid);
        int start = s;
        for(int i = 0;i<low.size();i++){
            low[i] = a[start++];
        }
        
        for(int i = 0;i<high.size();i++){
            high[i] = a[start++];
        }
        start = s;
        int j =0,k=0;
        while( j< low.size() && k < high.size()){
            if(low[j] < high[k]){
                a[start++] = low[j++];
            }else{
                a[start++] = high[k++];
            }
        }
        while(j<low.size()){
            a[start++] = low[j++];
        }
        while( k < high.size()){
            a[start++] = high[k++];
        }
    }
    void sort(vector<int>&a, int s, int e){
        if(s>=e) return;
        int mid = (s+e)/2;
        sort(a,s,mid);
        sort(a,mid+1,e);
        merge(a,s,e);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        sort(nums,0,nums.size()-1);
        return nums;
    }
};