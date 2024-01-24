// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int>vis(10,0);
        solve(root,ans,vis);
        return ans;
    }
    void solve(TreeNode* root, int &ans, vector<int>&vis){
        if (!root)
        return;

        vis[root->val]++;
        if (!root->left && !root->right) {
            int oddCount = 0;
            for (int i = 1; i < 10; ++i) {
                if (vis[i] % 2 == 1) {
                    oddCount++;
                }
            }
            if (oddCount <= 1) {
                ans++;
            }
        }

        solve(root->left, ans, vis);
        solve(root->right, ans, vis);

        vis[root->val]--;
        
    }
};