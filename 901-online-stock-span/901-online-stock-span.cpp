class StockSpanner {
public:
    int i=0;
    int ans=0;
    stack<pair<int,int>>st;
    
 
    StockSpanner() {
        
    }
    
    int next(int price) {
        
       while(!st.empty() && price>= st.top().first){
           
           st.pop();
           
       } 
        if(st.empty()) ans= i+1;
        else{
            ans = i-st.top().second;
        }
        
        st.push({price,i});
        i++;
        return ans;
        // while(!st.empty() && st.top()<=price) st.pop();
        // if(st.empty()) ans=i+1;
        // else{
        //     ans= i-st.top();
        // }
        // st.push(price);
        // i++;
        // return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */