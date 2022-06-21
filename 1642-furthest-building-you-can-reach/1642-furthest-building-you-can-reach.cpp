class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int>q;
        int i=0;
        for(;i<h.size()-1;i++){
            int diff =h[i+1] - h[i];
            if( diff <0 ) continue;
            bricks-= diff;
            q.push(diff);
            if(bricks<0){
                ladders--;
                bricks+=q.top();
                q.pop();
            }
            if(ladders<0){
                return i;
            }
        }
        return i;
    }
};