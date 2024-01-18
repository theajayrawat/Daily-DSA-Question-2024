// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        int maxi=root->val,mini=root->val;
        int diff=0;
        solve(root,maxi,mini,diff);
        return diff;
    } 
    void solve(TreeNode* root, int maxi, int mini, int &diff){
        if(!root)
            return;
        diff=max(diff, max(abs(maxi-root->val),abs(root->val-mini)));
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);

        solve(root->left,maxi,mini,diff);
        solve(root->right,maxi,mini,diff);
    }   
};