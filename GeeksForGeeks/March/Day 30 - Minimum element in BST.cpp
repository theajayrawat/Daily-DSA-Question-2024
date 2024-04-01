// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
// TC: O(N)
// SC: O(1)

class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(root->left == NULL) {
            return root->data;
        }
        return minValue(root->left);
    }
};