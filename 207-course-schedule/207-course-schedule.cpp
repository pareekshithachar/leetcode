class Solution {
public:
    int count =0;
    void dfs(vector<vector<int>>&g,int i,vector<int>&visited){
        if(visited[i] == 2) return;

        visited[i]=1;
        for(auto x : g[i]){
            if(visited[x] == 1){
                count =1;
                return;
            }
            dfs(g,x,visited);
        }
        visited[i]=2;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int> visited(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                    dfs(g,i,visited);
            }
            

        }
        return count == 1?false : true;
    }
};