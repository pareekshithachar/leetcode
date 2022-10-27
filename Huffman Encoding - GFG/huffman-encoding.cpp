//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    class Node {
        public:
            int data;
            Node* left;
            Node*right;
            
            Node(int data){
                this->data = data;
                left = NULL;
                right = NULL;
            }
    };
    class comp{
        public :
        bool operator()(Node* a, Node* b){
        return a->data > b->data;
        }
    };
    
    
	public:
	    void solve(Node* node, vector<string>&ans, string temp){
	        if(node->right == NULL && node->left == NULL){
	            ans.push_back(temp);

	            return ;
	        }
	        solve(node->left,ans, temp+'0');
	        solve(node->right,ans, temp+'1');
	        
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>, comp> q;
		    for(int i=0;i<N;i++){
		        Node* newnode = new Node(f[i]);
		        q.push(newnode);
		    }
		    
		    while(q.size() > 1){
		        Node* left = q.top();
		        q.pop();
		        Node* right = q.top();
		        q.pop();
		        
		        Node* newnode= new Node(left->data + right->data);
		        
		        newnode->left = left;
		        newnode->right = right;
		        q.push(newnode);
		    }
		    Node* root = q.top();
		    
		    vector<string>ans;
		    string temp = "";
		    
		    solve(root,ans,temp);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends