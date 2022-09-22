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
    set<TreeNode*> covered;
    
    int cam=0;
    void dfs(TreeNode* node, TreeNode* parent){
        if(node != NULL){
            dfs(node->left, node);
            dfs(node->right, node);
            if((parent == NULL && !covered.count(node)) || !covered.count(node->right) || !covered.count(node->left) ){
                cam++;
                covered.insert(parent);
                covered.insert(node);
                covered.insert(node->right);
                covered.insert(node->left);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        covered.insert(NULL);
        // covered.insert(root);
        if(root == NULL) return 0;
        dfs(root, NULL);
        return cam;
    }
};