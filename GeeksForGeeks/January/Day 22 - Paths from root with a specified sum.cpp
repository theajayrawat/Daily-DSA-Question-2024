// https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
// T.C : O(N^2)
// S.C : O(N)

class Solution
{
    public:
    
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(Node *root, int sum){
        if(root==NULL)
        return;
        
        sum-=root->key;
        temp.push_back(root->key);
        
        
        if(sum==0){
             ans.push_back(temp);
        }
       
     
        solve(root->left,sum);
        solve(root->right,sum);
        sum+=root->key;
        temp.pop_back();
       
    }
    vector<vector<int>> printPaths(Node *root, int sum){
        solve(root,sum);
        return ans;
    }
};

