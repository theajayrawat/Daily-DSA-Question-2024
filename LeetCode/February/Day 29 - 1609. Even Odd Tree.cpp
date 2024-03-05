// https://leetcode.com/problems/even-odd-tree/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return true;
        if(!root->left && !root->right){
            if(root->val%2)
                return true;
            return false;
        }

        queue<TreeNode*>q;
        q.push(root);
        bool even=true;
        while(!q.empty())
        {
            int qSize=q.size();
            int prev=-1;
            while(qSize--)
            {
                TreeNode*temp=q.front();
                q.pop();
                if((even && temp->val%2 && (prev<temp->val || prev==-1))||(!even && temp->val % 2 == 0 && (prev>temp->val  || prev==-1))){
                        prev=temp->val;
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }else{
                    return false;
                }
            }
            even=!even;   
        }

        return true;
    }
};