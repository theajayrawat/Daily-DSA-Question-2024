// https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
// TC: O(N)
// SC: O(N)

class Solution
{
    int prevValue=-1;
    int minDiff=INT_MAX;
    public:
    void inorder(Node *root){
        if(root==NULL) return;
        inorder(root->left);
        
        if(prevValue!=-1){
            minDiff = min(minDiff, abs(prevValue - root->data));
        }
        
        prevValue=root->data;
     
        inorder(root->right);
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        inorder(root);
        return minDiff;
    }
};