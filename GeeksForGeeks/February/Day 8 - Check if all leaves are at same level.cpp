// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
// TC: O(N)
// SC: O(N)

class Solution{
  public:
    /*You are required to complete this method*/
    
    bool solve(Node* root, int lev, int &ans){
        if(!root)
            return true;
        if(!root->left && !root->right){
            if(ans==-1 || ans==lev){
                ans=lev;
                return true;
            }
            
            return false;
            
        }
             
        return solve(root->left,lev+1,ans) && solve(root->right,lev+1,ans);
        
    }
    bool check(Node *root)
    {
        //Your code here
        int ans=-1;
        return solve(root,0,ans);
        
    }
};