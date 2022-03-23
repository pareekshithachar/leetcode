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
    
    unordered_map<TreeNode*,int> mp;
    int dfs(TreeNode* q){
        if(!q) return 0;
        
        if(mp.count(q)) return mp[q];
        
        //do not include root:
        int doNotInclude = dfs(q->left) + dfs(q->right);
        
        //include
        int include = q->val;
        
        if(q->left){
            if(q->left->left){
                include += dfs(q->left->left);
            }
            if(q->left->right){
                include += dfs(q->left->right);
            }
        }
        
        if(q->right){
             if(q->right->left){
                include += dfs(q->right->left);
            }
            if(q->right->right){
                include += dfs(q->right->right);
            }
        }
        
        return mp[q] = max(include, doNotInclude);
            
        
    }
    int rob(TreeNode* root) {
        return dfs(root);
        // return mp[root]; 
    }
};