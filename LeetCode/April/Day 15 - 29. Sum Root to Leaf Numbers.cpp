// hhttps://leetcode.com/problems/sum-root-to-leaf-numbers/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int ans=0;
        help(root,sum,ans);
        return ans;
    }
    void help(TreeNode*root,int sum, int &ans){
        if(!root)return;
        if(!root->left && !root->right){
            sum=sum*10+root->val;
            ans+=sum;
            return;
        }

        help(root->left,sum*10+root->val,ans);
        help(root->right,sum*10+root->val,ans);
    }
};