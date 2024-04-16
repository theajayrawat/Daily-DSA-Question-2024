// https://leetcode.com/problems/add-one-row-to-tree/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    void solve(TreeNode* root, int val, int depth, int currDepth){
        if(!root)
            return; 
        if(depth-1==currDepth){
            TreeNode* rootleft=root->left;
            TreeNode* rootright=root->right;
            root->left= new TreeNode(val);
            root->right= new TreeNode(val);
            root->left->left=rootleft;
            root->right->right=rootright;
            return;
        }
        solve(root->left,val,depth,currDepth+1);
        solve(root->right,val,depth,currDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot= new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }

        solve(root,val,depth,1);
        return root;
    }
};