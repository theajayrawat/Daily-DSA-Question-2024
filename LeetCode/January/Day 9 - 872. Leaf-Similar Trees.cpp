// https://leetcode.com/problems/leaf-similar-trees/
// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    bool ans=true;
    void leaf(TreeNode* root,  queue<int>&q, bool load){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(load)
                q.push(root->val);
            else{
                if(q.front()!=root->val){
                    ans=false;
                }
                if(q.size()==0)
                    ans=false;
                else
                    q.pop();
                   
            }
            return;
        }

        leaf(root->left,q,load);
        leaf(root->right,q,load);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int>q;
        leaf(root1,q,true);
        leaf(root2,q,false);
        if(q.size()!=0)
            return false;
        return ans;
    }
};