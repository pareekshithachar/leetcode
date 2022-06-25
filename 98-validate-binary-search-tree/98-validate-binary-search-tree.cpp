class Solution {
public:
    long maxi= (-1* pow(2,31)) - 1;
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL) return true;
        bool temp = isValidBST(root->left);
        if(maxi >= root->val) return false;
        maxi = root->val;
        bool temp1 = isValidBST(root->right);
        return temp && temp1;
    }
};