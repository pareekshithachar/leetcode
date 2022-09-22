class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
       vector<vector<char>>rotate(n, vector<char>(m));
        
        for(int i=0;i<m;i++){
            int free =0;
            // int freejidx=-1;
            // queue<int>q;
            priority_queue<int>q;
            for(int j=n-1;j>=0;j--){
                if(box[i][j] == '*'){
                    
                    while(!q.empty()) q.pop();
                }
                if(box[i][j] == '.'){
                    q.push(j);
                    
                }else{
                    
                    if(!q.empty()){
                        int front = q.top();
                        
                        q.pop();
                        q.push(j);
                        box[i][j] = '.';
                        box[i][front] = '#'; 
                    }
                }
                
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                    rotate[j][m-1-i] =box[i][j];
                
            }
        }
        return rotate;
    }
};