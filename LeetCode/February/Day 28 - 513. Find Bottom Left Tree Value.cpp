// https://leetcode.com/problems/find-bottom-left-tree-value/
// TC: O(N)
// SC: O(1)

class Solution {
public:
     int findBottomLeftValue(TreeNode* root) {
        if(!root)return 0;
        if(!root->left&&!root->right)return root->val;
        int ans=0;
        int depth=0;
        help(root,depth,0,ans);
        return ans;
    }
    void help(TreeNode* root,int &depth,int traverse,int &ans){
        if(!root)return;
        if(depth<traverse){
            depth=traverse;
            ans=root->val;
        }
        help(root->left,depth,traverse+1,ans);
        help(root->right,depth,traverse+1,ans);
    }
};