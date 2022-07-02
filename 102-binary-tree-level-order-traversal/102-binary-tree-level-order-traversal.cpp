class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int qlen=q.size();
            vector<int> curr;
            
            for(int i=0;i<qlen;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node!=NULL)
                {
                    curr.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right)q.push(node->right);
                    
                }
                
                
            }
            
            ans.push_back(curr);
            
        }
        
        return ans;
            
    }
};