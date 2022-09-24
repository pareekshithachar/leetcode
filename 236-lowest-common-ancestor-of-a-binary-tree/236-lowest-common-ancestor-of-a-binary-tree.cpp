/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> ancestor;
    
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        if(node->left) ancestor[node->left] = node;
        if(node->right) ancestor[node->right] = node;
        dfs(node->left);
        dfs(node->right);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestor[root] = root;
        dfs(root);
        set<TreeNode*> s;
        while(p!= root){
            s.insert(p);
            p = ancestor[p];
        }
        while(q!= root){
            if(!s.count(q))s.insert(q);
            else{
                return q;
            }
            q = ancestor[q];
        }
        
        return root;
    }
};