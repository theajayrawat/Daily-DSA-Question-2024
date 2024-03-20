// https://www.geeksforgeeks.org/problems/possible-paths--141628/1
// TC: O(N)
// SC: O(N)

class Solution
{
public:
    
    public:
    
    int height=1;
    int sum=0;
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        sum=root->data;
        dfs(root,0,1);
        return sum;
        
    }
    void dfs(Node* root,int data,int lvl)
    {
        if(root==NULL)
        {
            if(height==lvl-1)    
            {
                sum=max(sum,data);
            }
            else if(height<lvl-1)      
            {
                height=lvl-1;     
                sum=data;
            }
            return;
        }
        dfs(root->left,data+root->data,lvl+1);
        dfs(root->right,data+root->data,lvl+1);
    }
};