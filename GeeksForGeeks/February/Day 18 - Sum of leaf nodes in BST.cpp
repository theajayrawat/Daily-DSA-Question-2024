// https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1
// TC: O(N)
// SC: O(N)

class Solution
{
    public:
        /*You are required to complete below method */
        int sum = 0;
        void solve(Node *root){
            if(root==NULL)return ;
            
            if(root->left==NULL && root->right==NULL) sum+=root->data;
             if(root->left!=NULL) solve(root->left);
             if(root->right!=NULL) solve(root->right);
        }
        
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
           
              solve(root);
              return sum;
        }
};