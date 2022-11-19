//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(st.empty()) return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(st.empty()) return -1;
           //Write your code here
           int ans = st.top();
           st.pop();
           if(ans > minEle) return ans;
           else{
               int prevmin = minEle;
               int newmin = 2*minEle - ans;
               minEle = newmin;
               return prevmin;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           
           if(st.empty()){
               minEle = x;
               st.push(x);
           }else{
               if(x < minEle){
                   int val = 2*x - minEle;
                   st.push(val);
                   minEle = x;
               }else{
                   st.push(x);
               }
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends