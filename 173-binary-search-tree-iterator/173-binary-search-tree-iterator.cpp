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
class BSTIterator {
public:
    TreeNode* i;
    vector<TreeNode*>nodes;
    int idx;
    BSTIterator(TreeNode* root) {
        inorder(root);
        idx =0;
    }
    
    int next() {
        return nodes[idx++]->val;
    }
    
    bool hasNext() {
        return idx != nodes.size();
    }
    void inorder(TreeNode *root){
        if(not root ) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */