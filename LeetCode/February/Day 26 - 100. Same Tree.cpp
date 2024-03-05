// https://leetcode.com/problems/same-tree/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if(root1 && !root2)
        return false;
    else if(!root1 && root2)
        return false; 
    else if(!root1 && !root2)
        return true;


    int left=isSameTree(root1->left,root2->left);
    int right=isSameTree(root1->right,root2->right);

    return root1->val==root2->val && left && right;
    }
};