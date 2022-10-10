//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int count=0;
  void counter(Node* node){
      if(!node) return ;
      counter(node->right);
      count++;
      counter(node->left);
  }
  bool iscbt(Node* node, int i){
      if(node == NULL) return true;
      if(i >= count) return false;
      
      bool left = iscbt(node->left, 2*i + 1);
      bool right = iscbt(node->right, 2*i + 2);
      return left && right;
  }
    pair<bool,int> solve(Node* node){
        
        
        if(node == NULL){
            return {true,INT_MIN};
        }
        
        if(node->right && node->left == NULL){
            return {false,0};
        }
        
        pair<bool,int>left = solve(node->left);
        pair<bool,int>right = solve(node->right);
        
        
        pair<bool,int>ans;
        
        ans.second = max({left.second,right.second, node->data});
        if(left.first && right.first && (node->data > right.second) && (node->data > left.second) ){
            
                 ans.first = true;
                
        }else{
            ans.first = false;
        }
        return ans;
    }
    bool isHeap(struct Node* tree) {
        // code here
        counter(tree);
        if(!iscbt(tree,0)) return false;
        return solve(tree).first;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends