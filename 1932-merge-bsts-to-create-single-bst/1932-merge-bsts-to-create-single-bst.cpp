class Solution {
	//Map to store the index of the root, given its value
    unordered_map<int, int> mp; 
public:
	//Perform DFS and simultaneously build tree
    void dfs(vector<TreeNode*>& trees, vector<bool>& vis, TreeNode* node){
        if(node->left!=NULL && mp[node->left->val]>0){
            node->left = trees[mp[node->left->val]-1];
            vis[mp[node->left->val]-1] = true;
            mp[node->left->val] = 0;
            dfs(trees, vis, node->left);
        }
        if(node->right!=NULL && mp[node->right->val]>0){
            node->right = trees[mp[node->right->val]-1];
            vis[mp[node->right->val]-1] = true;
            mp[node->right->val] = 0;
            dfs(trees, vis, node->right);
        }
    }
    
	//Function to validate the BST formed. It checks for the conditions for a valid BST as given in question by doing DFS
    bool validate(TreeNode* root, int up = INT_MIN, int low = INT_MAX){
        if(root==NULL)
            return true;
        if(root->val >= low || root->val <= up)
            return false;
        return validate(root->left, up, root->val)&&validate(root->right, root->val, low);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, int> ump;
        for(int i=0; i<trees.size(); i++){
            if(trees[i]->left != NULL)
                ump[trees[i]->left->val] = 1;
            if(trees[i]->right != NULL)
                ump[trees[i]->right->val] = 1;
        }
        for(int i=0; i<trees.size(); i++)
            mp[trees[i]->val] = i+1;
        
        vector<bool> vis(trees.size(), false);
        TreeNode* root = NULL;
        for(int i=0; i<trees.size(); i++){
            if(!ump[trees[i]->val]){
                vis[i] = true;
                root = trees[i];
                break;
            }
        }
        if(root==NULL)
            return NULL;
        mp[root->val] = 0;
        dfs(trees, vis, root);
        
        for(int i=0; i<vis.size(); i++)
            if(!vis[i])
                return NULL;
        
        if(validate(root))
            return root;
        
        return NULL;
    }
};