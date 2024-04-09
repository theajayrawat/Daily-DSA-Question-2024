// https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1
// TC: O(N)
// SC: O(1)

class Solution
{
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        vector<int> arr;
        helper(root,x,y,arr);
        if(arr.size()>=k){
            return arr[k-1];
        }
        return -1;
    }
    static void helper(Node *root,int x,int y,vector<int>&arr){
        if(root==NULL){
            return;
        }
        if(root->data>x && root->data>y){
            helper(root->left,x,y,arr);
        }
        if(root->data<x && root->data<y){
            helper(root->right,x,y,arr);
        }
        arr.push_back(root->data);
    }
};

