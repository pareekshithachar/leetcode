//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    vector<vector<int>>board(N,vector<int>(N,-1));
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0]-1, KnightPos[1]-1});
	    board[KnightPos[0]-1][KnightPos[1]-1] = 0;
	    
	    vector<int>rows = {1,1,-1,-1,2,-2,2,-2};
	    vector<int>cols = {2,-2,2,-2,1,1,-1,-1};
	    while(!q.empty()){
	        auto front = q.front();
	        q.pop();

	        int oldi = front.first;
	        int oldj = front.second;
	        for(int i = 0;i<8;i++){
	            int newi = oldi + rows[i];
	            int newj = oldj + cols[i];
	            if(!(newj < 0 || newj >=N || newi<0 || newi >= N || board[newi][newj] != -1)){
	                board[newi][newj] = board[oldi][oldj] + 1;
	                q.push({newi,newj});
	            }
	        }
	       
	    }
	    return board[TargetPos[0]-1][TargetPos[1]-1];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends