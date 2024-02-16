// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
// TC: O(N)
// SC: O(N)

class Solution
{
public:
    void inorder(Node* curr , Node* &prev)
    {
        if(!curr) return ;
        
        inorder(curr->left , prev);
        
        curr->left = NULL;
        prev->right = curr;
        prev = curr;
        
        inorder(curr->right , prev);
    }
    Node *flattenBST(Node *root)
    {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        
        inorder(root , prev);
        
        return dummy->right;
    }
};