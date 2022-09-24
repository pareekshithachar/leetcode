/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&in){
        if(root == NULL) return;
        in.push_back(root->val);
        inorder(root->left,in);
        inorder(root->right,in);
        
    }
    void flatten(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        
        // TreeNode* head = new TreeNode(in[0]);
        if(root == NULL){
            return;
        }
        TreeNode* cur= root;
        for(auto x : in){
            cout<<x<<" ";
        }
        for(int i=1;i<in.size();i++){
            TreeNode* temp = new TreeNode(in[i]);
            
            cur-> right = temp;
            cur->left = NULL;
            cur = temp;
        }
        cur->right = NULL;
        cur->left = NULL;
        
    }
};