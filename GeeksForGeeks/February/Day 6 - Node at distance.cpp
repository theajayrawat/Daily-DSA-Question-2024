// https://www.geeksforgeeks.org/problems/node-at-distance/1
// TC: O(N)
// SC: O(N)

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    void help( Node * root, int k, int level, vector<pair<int,Node *>> s, set<pair<int,Node*>>&ans){
        if(root == NULL)return;
        
        if(root-> left == NULL && root->right == NULL){
            if(k == 0){
                ans.insert(make_pair(root->data, root););
            }
            else if(level >= k){
                pair<int,Node*> t = s[level - k];
                ans.insert(make_pair(t.first,t.second););
            }
        }
        
        s.push_back({root->data,root});
        help(root->left, k, level+1, s, ans);
        help(root->right, k, level+1, s, ans);
    }
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        set<pair<int,Node*>> ans;
        vector<pair<int,Node *>> s;
        help(root, k, 0, s, ans);
        return ans.size();
    }
};