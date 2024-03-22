// https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
  void trav(Node* root,int d,map<int,int> &vals)
  {
      if(root==NULL)
      return ;
      
      vals[d]+=root->data;
      trav(root->left,d+1,vals);
      trav(root->right,d,vals);
      
  }
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        map<int,int> vals;
        trav(root,0,vals);
        vector<int> ans;
        for(auto x:vals)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};