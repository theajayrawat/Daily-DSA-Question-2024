// https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int findDist(Node* root, int a, int b) {
        Node* lca = lowestCommonAncestor(root, a, b);
        return lcaDistance(lca, a) + lcaDistance(lca, b);
    }

private:
    int lcaDistance(Node* node, int target) {
        if (!node) return -1;
        if (node->data == target) return 0;
        
        int left = lcaDistance(node->left, target);
        int right = lcaDistance(node->right, target);
        
        if (left >= 0) return left + 1;
        if (right >= 0) return right + 1;
        
        return -1;
    }

    Node* lowestCommonAncestor(Node* node, int a, int b) {
        if (!node) return nullptr;
        if (node->data == a || node->data == b) return node;
        
        Node* leftLCA = lowestCommonAncestor(node->left, a, b);
        Node* rightLCA = lowestCommonAncestor(node->right, a, b);
        
        if (leftLCA && rightLCA) return node;
        
        return leftLCA ? leftLCA : rightLCA;
    }
};



