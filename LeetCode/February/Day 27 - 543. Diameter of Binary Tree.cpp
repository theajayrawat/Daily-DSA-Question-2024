// https://leetcode.com/problems/diameter-of-binary-tree/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        gethght(root, ans);
        return ans;
    }
    int gethght(TreeNode* root,int &ans){
        if(!root)return 0;
        int lh=gethght(root->left,ans);
        int rh=gethght(root->right,ans);
        ans=max(ans,lh+rh);
        return 1+max(lh,rh);
    }
};