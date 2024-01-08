// https://leetcode.com/problems/range-sum-of-bst/
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        if(root->val>=low && root->val<=high){
            return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
        if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }

        return rangeSumBST(root->left,low,high);
    }
};



