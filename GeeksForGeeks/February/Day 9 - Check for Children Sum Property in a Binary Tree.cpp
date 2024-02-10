// https://www.geeksforgeeks.org/problems/children-sum-parent/1
// TC: O(N)
// SC: O(H)

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool solve(Node* root){
        if(!root) 
            return true;
        
        if(!root->left && !root->right)
            return true;
        bool left=solve(root->left);
        bool right=solve(root->right);
        
        if(!(left && right))
            return false;
        
        int sum=0;
        if(root->left)
            sum+=root->left->data;
        if(root->right)
            sum+=root->right->data;
        
        return sum==root->data && left && right;
        
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
        return solve(root);
    }
};