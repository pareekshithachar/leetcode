class Solution {
public:

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long int maxx=0;
        long int maxy=0;
        long int modul=1000000000 + 7;
        horizontalCuts.insert(horizontalCuts.begin(),0);
        verticalCuts.insert(verticalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
       
        
        for(int i=0;i<horizontalCuts.size()-1;i++){
            maxx = max(maxx,(horizontalCuts[i+1]%modul-horizontalCuts[i]%modul));
            
            
        }
        for(int i=0;i<verticalCuts.size()-1;i++){
            maxy = max(maxy,verticalCuts[i+1]%modul-verticalCuts[i]%modul);
            
        }
        return (maxx)*(maxy) %modul;
    }
};