// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
// TC: O(N)
// SC: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<pair<TreeNode*,int>>st;
    int min=0;
    bool find=false;
    void solve(TreeNode* root, int start){
        if(!root || find)
            return;
        if(root->val==start){
            st.push(make_pair(root,min++));
            find=true;
            return;
        }

        solve(root->left,start);
        solve(root->right,start);
        if(find) 
            st.push(make_pair(root,min++));
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root || (!root->left && !root->right))
            return 0;
        solve(root,start);
        int ans=min-1;
        int size=st.size();
        queue<pair<TreeNode*,int>>q;
        while(size--){
            auto i=st.top();
            st.pop();
            q.push(i);
        }
       
        while(!q.empty()){
            int qSize=q.size();
            while(qSize--){
                 pair<TreeNode*,int>p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int time=p.second+1;
            if(qSize!=0){
                if(temp->left && temp->left!=q.front().first){
                    q.push(make_pair(temp->left,time));
                    ans=max(ans,time);
                }if(temp->right && temp->right!=q.front().first){
                    q.push(make_pair(temp->right,time));
                     ans=max(ans,time);
                }
            }else{
                if(temp->left){
                    q.push(make_pair(temp->left,time));
                     ans=max(ans,time);
                }if(temp->right){
                    q.push(make_pair(temp->right,time));
                     ans=max(ans,time);
                }
            }

            }
            cout<<endl;
           
        }

        return ans; 
    }
};