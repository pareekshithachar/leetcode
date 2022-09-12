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
    
    int solve(TreeNode* node, int c){
     if(node->left == NULL && node->right == NULL){
         
         return c;
     }
     int temp1 =0;
     int temp2=0;
     
     if(node->left){
         cout<<"yes"; 
         temp1 = solve(node->left,c+1);
         
     } 
     if(node->right){
         temp2 = solve(node->right,c+1);
     } 
     return max(temp1,temp2);
 }
    
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return solve(root,1);
    }
};