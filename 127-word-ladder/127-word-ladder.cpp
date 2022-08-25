class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string,int>sti;
        unordered_map<int,string>its;
        int flag = 1;
        for(int i=0;i<wordList.size();i++){
            sti[wordList[i]] = i;
            its[i] = wordList[i];
            if(wordList[i] == endWord){
                flag =0;
            }
        }
        if(flag == 1) return 0;
        
        vector<vector<int>>g(wordList.size());
        for(int i=0;i<wordList.size()-1;i++){
            for(int j = i+1;j<wordList.size();j++){
                int count =0;
                for(int k=0;k<beginWord.size();k++){
                    if(wordList[i][k] == wordList[j][k]){
                        count++;
                    }
                }
                if(count == beginWord.size() - 1){
                    
                    g[sti[wordList[i]]].push_back(sti[wordList[j]]);
                    g[sti[wordList[j]]].push_back(sti[wordList[i]]);
                }
            }
        }
        vector<int>cost(wordList.size(),INT_MAX);
        cost[sti[beginWord]] = 0;
        queue<int>q;
        q.push(sti[beginWord]);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto x : g[top]){
                if(cost[x] > cost[top] + 1 ){
                    cost[x] = cost[top] + 1;
                    q.push(x);
                    cout<<its[x]<<" " <<cost[x]<<" ";
                }
            }
        }
       
        return cost[sti[endWord]] == INT_MAX? 0 : cost[sti[endWord]] +1;
    }
};